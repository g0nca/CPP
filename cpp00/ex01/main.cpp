/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:48:55 by ggomes-v          #+#    #+#             */
/*   Updated: 2026/02/25 13:56:21 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int     main(void)
{
    PhoneBook   phonebook;
    std::string cmdline;
    std::string tmp_cmd_line;

    std::cout << "   Welcome to PhoneBook   " << std::endl;
    while (1)
    {
        std::cout << "-> Options :\n      ADD\n      SEARCH\n      EXIT" << std::endl;
        if (!std::getline(std::cin, cmdline))
            break ;
        if (cmdline == "ADD")
        {
            phonebook.add();
        }
        else if (cmdline == "SEARCH")
        {
            phonebook.search();
        }
        else if (cmdline == "EXIT")
            break ;
        else
        {
            std::cout << "Invalid Option" << std::endl;
            std::cout << "Available options: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    return (0);
}
