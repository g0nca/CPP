/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:53:10 by ggomes-v          #+#    #+#             */
/*   Updated: 2026/01/08 15:43:31 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
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