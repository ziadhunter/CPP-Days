/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 02:59:09 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 19:39:59 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
    this->_name = "unknown";
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
        this->_name = other._name;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
    {
        throw GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
    {
        throw GradeTooLowException();
    }
    this->_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << this->getName() << " couldn't sign "
            << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm& form)
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " execute " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << this->getName() << " couldn't execute "
            << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << std::endl;
    return os;
}
