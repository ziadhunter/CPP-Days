/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:39:21 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 17:17:12 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	this->_name = "empty";
	this->_grade_to_sign = 150;
	this->_grade_to_exec = 150;
	this->_signed = 0;
}

Form::Form(std::string name, int sign_grad, int exec_grad)
{
	if (sign_grad < 1 || exec_grad < 1)
		throw Form::GradeTooHighException();
	if (sign_grad > 150 || exec_grad > 150)
		throw Form::GradeTooLowException();
	this->_name = name;
	this->_grade_to_sign = sign_grad;
	this->_grade_to_exec = exec_grad;
	this->_signed = 0;
}

Form::Form(const Form& other)
{
    *this = other;
}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade_to_sign = other._grade_to_sign;
        this->_grade_to_exec = other._grade_to_exec;
        this->_signed = other._signed;
    }
    return *this;
}

const std::string& Form::getName() const
{
    return (this->_name);
}

int Form::getExecGrade() const
{
    return (this->_grade_to_exec);
}

int Form::getSignGrade() const
{
    return (this->_grade_to_sign);
}

void Form::beSigned(const Bureaucrat& br)
{
	if (br.getGrade() > this->getSignGrade())
	{
		throw GradeTooLowException();
	}
	this->_signed = 1;
}

std::ostream& operator<<(std::ostream& os, Form& fr)
{
    os << "form name: " << fr.getName() <<  ", grade required to sign: " << fr.getSignGrade() 
        << ", grade required to execute : " << fr.getExecGrade() << std::endl;
    return (os);
}

