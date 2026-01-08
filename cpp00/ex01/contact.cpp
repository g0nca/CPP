/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:49:08 by ggomes-v          #+#    #+#             */
/*   Updated: 2026/01/08 14:36:49 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void){
    
}

Contact::~Contact(void){
    
}

/* ----------------- Getters -----------------
    Getters are used to access private data of a class.
    std::string is the return type (the type of data we are retrieving).
    Contact specifies the class scope (which class this function belongs to).
    getFirstName is the name of the getter method, which takes no arguments.
    return (this->firstName) returns the value stored in the firstName member variable of the Contact class.
    (this->) is an operator used to point to actual object
*/

std::string    Contact::getfirstName(void){
    return (this->firstName);
}

std::string     Contact::getlastName(void){
    return (this->lastName);
}

std::string     Contact::getnickName(void){
    return (this->nickName);
}

std::string     Contact::getphoneNumber(void){
    return(this->phoneNumber);
}

std::string     Contact::getsecret(void){
    return (this->secret);
}

/* ----------------- Setters -----------------
    Setters are used to modify private member variables of a class.
    void is the return type, indicating the function returns no value.
    Contact specifies the class scope
    setFirstName is the name of the setter method.
    (std::string str) is the parameter passed to the function, which contains the new value to be stored.
*/
void            Contact::setfirstName(std::string str){
    this->firstName = str;
}

void            Contact::setlastName(std::string str){
    this->lastName = str;
}

void            Contact::setnickName(std::string str){
    this->nickName = str;
}

void            Contact::setphoneNumber(std::string str){
    this->phoneNumber = str;
}

void            Contact::setsecret(std::string str){
    this->secret = str;
}