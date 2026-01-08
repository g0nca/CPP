/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:49:06 by ggomes-v          #+#    #+#             */
/*   Updated: 2026/01/08 15:26:57 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string secret;
    
    public:
        Contact(void);
        ~Contact(void);
        std::string     getfirstName(void);
        std::string     getlastName(void);
        std::string     getnickName(void);
        std::string     getphoneNumber(void);
        std::string     getsecret(void);
        void            setfirstName(std::string str);
        void            setlastName(std::string str);
        void            setnickName(std::string str);
        void            setphoneNumber(std::string str);
        void            setsecret(std::string str);
        
        
};

#endif