/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:34:24 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/27 21:51:53 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    phonebook.index = 0;
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, command);
        if (std::cin.eof())
            exit(1);
        if (command == "ADD")
        {
            phonebook.AddContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
            std::cout << "index after search: " << phonebook.index << std::endl;
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }

    return 0;
}