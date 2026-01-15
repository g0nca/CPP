/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:53:10 by ggomes-v          #+#    #+#             */
/*   Updated: 2026/01/15 14:43:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include "contact.hpp"

#define MAX_CONTACTS 8


class PhoneBook 
{
    private:
        Contact _contacts[8];
        int     _index;
        int     _savedCount;
    
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    add();
        void    search();
};

#endif