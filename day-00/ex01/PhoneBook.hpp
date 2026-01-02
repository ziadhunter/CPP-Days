/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:14:10 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/27 21:40:05 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook {
    private:
        Contact _contact[MAX_CONTACTS];
        int     _book_size;
    public:
        int  index;

        PhoneBook() : _book_size(0), index(0) {}
        
        void GetContactInfo(std::string info[5]);
        void AddContact();
        void display_contact_details(int index);
        int  display_all_contacts();
        void search_contact();
};


#endif