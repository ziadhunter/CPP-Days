/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:05:03 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 17:08:57 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ShrubberyCreationForm_HPP
#define  ShrubberyCreationForm_HPP

#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm:: ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const  ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const  ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor);
    
};

#endif