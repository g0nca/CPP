#include "phonebook.hpp"

PhoneBook::PhoneBook(void){
    this->_index = 0;
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

void    PhoneBook::search(){
    std::cout << "SEARCH" << std::endl;
}