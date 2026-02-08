/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:58:15 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 08:03:18 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string form_type, std::string target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (form_type == formNames[i])
        {
            std::cout << "Intern creates " << form_type << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "Error: form \"" << form_type << "\" does not exist." << std::endl;
    return NULL;
}
