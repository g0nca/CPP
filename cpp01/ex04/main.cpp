
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong number of Arguments" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string newfilename = filename + ".replace";

    if (s1.empty())
    {
        std::cout << "Error: empty string to replace" << std::endl;
        return (1);
    }
    
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Error: Failed opening the file" << std::endl;
        return (1);
    }

    std::ofstream outfile(newfilename.c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error Could not create output file" << std::endl;
        return (1);
    }

    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
    infile.close();
    outfile.close();
    return (0);
}