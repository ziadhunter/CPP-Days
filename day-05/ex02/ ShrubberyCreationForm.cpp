/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:19:01 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 17:09:31 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "unknown", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const  ShrubberyCreationForm& other)
{
    *this = other;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const  ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->set_attr(other.getName(), other.getTarget(),
                other.getIsSigned(), other.getSignGrade(), other.getExecGrade());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void execute(Bureaucrat const & executor)
{
    
}