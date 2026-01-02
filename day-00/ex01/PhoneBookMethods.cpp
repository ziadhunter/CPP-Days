/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookMethods.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:51:59 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/27 21:52:05 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::GetContactInfo(std::string info[5])
{
    int i;
    std::string contact_fields[5] = {
        "First Name: ",
        "Last Name: ",
        "Nickname: ",
        "Phone Number: ",
        "Darkest Secret: "
    };
    
    std::cout << "<<<Add a new contact>>>" << std::endl;
    i = 0;
    while (i < 5)
    {
        while (true)
        {
            std::cout << contact_fields[i] << std::endl;
            std::getline(std::cin, info[i]);
            if (std::cin.eof())
                exit(1);
            if (info[i].empty())
                std::cout << "this field cannot be empty. Please try again." << std::endl;
            else if (info[i].find_first_not_of(" \t\n\v\f\r") == std::string::npos)
                std::cout << "this field cannot be empty. Please try again." << std::endl;
            else
                break;
        }
        i++;
    }
}

void PhoneBook::AddContact()
{
    std::string info[5];

    GetContactInfo(info);
    Contact new_contact(info[0], info[1], info[2], info[3], info[4]);
    this->_contact[this->index % MAX_CONTACTS] = new_contact;
    this->index++;
    if (this->_book_size < MAX_CONTACTS)
        this->_book_size++;
}


int PhoneBook::display_all_contacts()
{
    int i;

    if (this->_book_size == 0)
    {
        std::cout << "PhoneBook is empty. Please add some contacts first." << std::endl;
        return (1);
    }
    std::cout << "     Index" << "|"
            << "First Name" << "|"
            << " Last Name" << "|"
            << "  Nickname" << std::endl;
    i = 0;
    while (i < this->_book_size)
    {
        std::cout << "         " << i + 1 << "|"
                  << this->_contact[i].get_first_name().substr(0, 10) << "|"
                  << this->_contact[i].get_last_name().substr(0, 10) << "|"
                  << this->_contact[i].get_nick_name().substr(0, 10) << std::endl;
        i++;
    }
    return (0);
}

void PhoneBook::display_contact_details(int index)
{
    if (index <= 0 || index > this->_book_size)
    {
        std::cout << "index out of range. Please try again." << std::endl;
        return;
    }
    std::cout << "First Name: " << this->_contact[index - 1].get_first_name() << std::endl;
    std::cout << "Last Name: " << this->_contact[index - 1].get_last_name() << std::endl;
    std::cout << "Nickname: " << this->_contact[index - 1].get_nick_name() << std::endl;
    std::cout << "Phone Number: " << this->_contact[index - 1].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << this->_contact[index - 1].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{
    int i;
    std::string command;
    if (this->display_all_contacts() == 1)
        return;
    std::cout << "Enter contact index to view details: ";
    std::getline(std::cin, command);
    if (std::cin.eof())
            exit(1);
    i = std::atoi(command.c_str());
    if (i <= 0 || i > this->_book_size)
    {
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }
    this->display_contact_details(i);
}