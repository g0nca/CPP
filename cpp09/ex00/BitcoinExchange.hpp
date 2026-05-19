#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>


class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;
        void    load_database(const std::string&);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& );
        BitcoinExchange& operator=(const BitcoinExchange& );
        ~BitcoinExchange();
        
        void    processInput(const std::string&);

        bool        isValidDate(const std::string &date) const;
        bool        isValidValue(const std::string &valStr, float &out) const;
        float       getRate(const std::string &date) const;
        void        printDatabase() const;

    class InvalidArguments : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Invalid number of arguments\n./btc input.csv");
            }
    };
    class EmptyFile : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Empty file");
            }
    };
    class WrongFilename : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Wrong filename");
            }
    };
    class CantOpenFile : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Permission denied to open file");
            }
    };
    class MissingParametersCSV : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Missing parameters on CSV - [date,exchange_rate]");
            }
    };
    class TrashOnDatabase : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Trash on Database, only accept Numbers");
            }
    };
    
};