#include "phonebook.hpp"

PhoneBook::PhoneBook(void){
    this->_index = 1;
    this->_savedCount = 0;
}

PhoneBook::~PhoneBook(void){
    
}

void    PhoneBook::add(){
    std::string first, last, nick, number, secret;
    std::cout << "First Name: " << std::endl;
    std::getline(std::cin, first);
    std::cout << "Last Name: " << std::endl;
    std::getline(std::cin, last);
    std::cout << "Nick Name: " << std::endl;
    std::getline(std::cin, nick);
    std::cout << "Phone Number: " << std::endl;
    std::getline(std::cin, number);
    std::cout << "Darkest Secret:" << std::endl;
    std::getline(std::cin, secret);
    if (first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
    {
        std::cout << "Invalid Input" << std::endl;
        return ;
    }
    this->_contacts[this->_savedCount % 8].setfirstName(first);
    this->_contacts[this->_savedCount % 8].setlastName(last);
    this->_contacts[this->_savedCount % 8].setnickName(nick);
    this->_contacts[this->_savedCount % 8].setphoneNumber(number);
    this->_contacts[this->_savedCount % 8].setsecret(secret);
    this->_savedCount++;
}

std::string     truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void    PhoneBook::search(){
    int x = 0;
    std::string index;

    if (this->_savedCount == 0)
    {
        std::cout << "Empty phonebook" << std::endl;
        return ;
    }
    std::cout << "Index | First name | Last name | Nickname" << std::endl;
    while (x < _savedCount && x < 8)
    {
        std::cout << x << " | ";
        std::cout << std::setw(10) << truncate(this->_contacts[x].getfirstName()) << " | ";
        std::cout << std::setw(10) << truncate(this->_contacts[x].getlastName()) << " | ";
        std::cout << std::setw(10) << truncate(this->_contacts[x].getnickName()) << std::endl;
        x++;        
    }
    std::cout << "Enter index of contact to view:" << std::endl;
    std::getline(std::cin, index);

    int i = index[0] - '0';

    if (index.empty() || i >= _savedCount || index.length() > 1 || index[0] < '0' || index[0] > '7')
    {
        std::cout << "Invalid input." << std::endl;
        return ;
    }
    else
    {
        std::cout << "First name:" << this->_contacts[index[0] - '0'].getfirstName() << std::endl;
        std::cout << "Last name:" << this->_contacts[index[0] - '0'].getlastName() << std::endl;
        std::cout << "Nickname:" << this->_contacts[index[0] - '0'].getnickName() << std::endl;
        std::cout << "Phone number:" << this->_contacts[index[0] - '0'].getphoneNumber() << std::endl;
        std::cout << "Darkest secret:" << this->_contacts[index[0] - '0'].getsecret() << std::endl;

    }
}