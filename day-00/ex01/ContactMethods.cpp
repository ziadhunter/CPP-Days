/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactMethods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:50:42 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/27 21:51:33 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string pnumber, std::string dsecret)
{
    first_name = fname;
    last_name = lname;
    nick_name = nname;
    phone_number = pnumber;
    darkest_secret = dsecret;
}

std::string Contact::get_first_name()
{
    return (this->first_name);
}

std::string Contact::get_last_name()
{
    return (this->last_name);
}

std::string Contact::get_nick_name()
{
    return (this->nick_name);
}

std::string Contact::get_phone_number()
{
    return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (this->darkest_secret);
}   