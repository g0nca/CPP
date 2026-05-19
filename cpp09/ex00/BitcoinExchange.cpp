#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
    load_database("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
    if (this != &copy)
    {
        this->_database = copy._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

static void rtrim(std::string &s);

/**
 * @brief Loads the Bitcoin exchange rate historical data from a CSV file into the internal database.
 * 
 * This function validates the filename extension, opens the file, skips the header line,
 * and parses the contents line by line. It extracts the date and exchange rate (separated by a comma),
 * strictly validates that the rate is a proper float with no trailing characters or overflow errors,
 * and populates the internal database map.
 * 
 * @param filename The path/name of the CSV file containing the historical exchange rates.
 * 
 * @throw BitcoinExchange::EmptyFile If the provided filename is empty.
 * @throw BitcoinExchange::MissingParametersCSV If the filename is shorter than 4 characters or does not end with ".csv".
 * @throw BitcoinExchange::CantOpenFile If the file cannot be opened or does not exist.
 * @throw BitcoinExchange::TrashOnDatabase If a row contains invalid, malformed, or out-of-range rate data.
 */
void    BitcoinExchange::load_database(const std::string &filename)
{
    if (filename.empty())
        throw(BitcoinExchange::EmptyFile());
    if (filename.size() < 4 || filename.rfind(".csv") != filename.size() - 4)
        throw(BitcoinExchange::MissingParametersCSV());
    std::ifstream   file(filename.c_str());
    if (!file.is_open())
        throw(BitcoinExchange::CantOpenFile());

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        rtrim(line);
        if (line.empty()) continue;

        size_t sep = line.find(',');

        std::string date = line.substr(0, sep);
        std::string rateStr = line.substr(sep + 1);

        const char *cstr = rateStr.c_str();
        char *end;
        errno = 0;
        float rate = std::strtof(cstr, &end);

        if (end == rateStr.c_str() || *end != '\0' || errno == ERANGE)
            throw(BitcoinExchange::TrashOnDatabase());
        _database[date] = rate;
    }
}

/**
 * @brief Processes an input file containing Bitcoin transactions and displays the converted values.
 * 
 * This function reads the specified file line by line, validates the format (Date | Value), 
 * verifies if the date is valid, and checks if the value is within acceptable limits. 
 * For each valid entry, it calculates the converted value based on the exchange rate for 
 * that specific date and prints the result to the standard output.
 * 
 * @param filename The path/name of the text file to be processed.
 * 
 * @throw BitcoinExchange::EmptyFile If the provided filename is empty.
 * @throw BitcoinExchange::CantOpenFile If the file cannot be opened or does not exist.
 */
void BitcoinExchange::processInput(const std::string &filename)
{
    if (filename.empty())
        throw EmptyFile();

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw CantOpenFile();

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        rtrim(line);
        if (line.empty()) continue;

        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valStr, value))
            continue;

        float rate = getRate(date);
        if (rate < 0)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}

/**
 * @brief Validates if a given string represents a real, correctly formatted calendar date.
 * 
 * This function performs strict validation on a date string following the YYYY-MM-DD format:
 * 1. Verifies the exact length is 10 characters.
 * 2. Checks for correct hyphen placements at indices 4 and 7.
 * 3. Ensures all other characters are numeric digits.
 * 4. Extracts and validates logical ranges for the year, month (1-12), and day (1-31).
 * 5. Accounts for varying days per month, including leap year calculations for February.
 * 
 * @param date The date string to be validated (expected format: "YYYY-MM-DD").
 * @return true If the string is a valid, logical calendar date.
 * @return false If the string is malformed or represents a non-existent calendar date.
 */
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10) return false;

    if (date[4] != '-' || date[7] != '-') return false;

    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap) daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1]) return false;

    return true;
}

/**
 * @brief Validates a numeric string value and ensures it falls within acceptable Bitcoin exchange limits.
 * 
 * This function attempts to safely parse a string into a float value using strict conversion checks.
 * If the conversion succeeds, it performs business-logic checks to ensure the value is positive 
 * and does not exceed the maximum allowed threshold (1000). Upon successful validation, 
 * the parsed value is assigned to an output reference variable.
 * 
 * @param valStr The numeric string to be validated.
 * @param out A reference to a float variable where the validated value will be stored.
 * 
 * @return true If the string is a valid number, fits in range, and is successfully assigned to 'out'.
 * @return false If the string is empty, malformed, out of numeric limits (< 0 or > 1000), or overflows.
 */
bool BitcoinExchange::isValidValue(const std::string &valStr, float &out) const
{
    if (valStr.empty())
    {
        std::cout << "Error: bad input => " << valStr << std::endl;
        return false;
    }

    const char *cstr = valStr.c_str();
    char *end;
    errno = 0;
    float val = std::strtof(cstr, &end);

    if (end == cstr || *end != '\0' || errno == ERANGE)
    {
        std::cout << "Error: bad input => " << valStr << std::endl;
        return false;
    }
    if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    out = val;
    return true;
}

/**
 * @brief Retrieves the Bitcoin exchange rate for a given date from the database.
 * 
 * This function searches the internal map for an exact match of the requested date. 
 * If the exact date does not exist in the database, it falls back to the closest 
 * lower date available (the most recent historical rate prior to the requested date).
 * 
 * @param date The lookup date in "YYYY-MM-DD" format.
 * 
 * @return float The exchange rate on that exact date, or the closest earlier date. 
 *               Returns 0 if the requested date is older than the earliest entry in the database.
 */
float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
        return it->second;
    if (it == _database.begin() && it->first != date)
        return -1;
    --it;
    return it->second;
}

void BitcoinExchange::printDatabase() const
{
    std::map<std::string, float>::const_iterator it;
    for (it = _database.begin(); it != _database.end(); ++it) 
        std::cout << "Date: " << it->first << " | Tax: " << it->second << std::endl;

}

static void rtrim(std::string &s)
{
    while (!s.empty() &&
           (s[s.size()-1] == '\r' ||
            s[s.size()-1] == '\n' ||
            s[s.size()-1] == ' '  ||
            s[s.size()-1] == '\t'))
        s.erase(s.size() - 1);
}