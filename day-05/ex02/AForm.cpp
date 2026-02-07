/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:39:21 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 19:23:18 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
{
	this->_name = "empty";
	this->_target = "unknown";
	this->_grade_to_sign = 150;
	this->_grade_to_exec = 150;
	this->_signed = 0;
}

AForm::AForm(std::string name, std::string target, int sign_grad, int exec_grad)
{
	if (sign_grad < 1 || exec_grad < 1)
		throw AForm::GradeTooHighException();
	if (sign_grad > 150 || exec_grad > 150)
		throw AForm::GradeTooLowException();
	this->_name = name;
	this->_target = target;
	this->_grade_to_sign = sign_grad;
	this->_grade_to_exec = exec_grad;
	this->_signed = 0;
}

AForm::AForm(const AForm& other)
{
    *this = other;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
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

const std::string& AForm::getName() const
{
    return (this->_name);
}

const std::string& AForm::getTarget() const
{
	return (this->_target);
}

int AForm::getExecGrade() const
{
    return (this->_grade_to_exec);
}

int AForm::getSignGrade() const
{
    return (this->_grade_to_sign);
}

bool AForm::getIsSigned() const
{
	return (this->_signed);
}

void AForm::set_attr(std::string name, std::string target, bool signede, int g_s, int g_e)
{
	this->_name = name;
	this->_target = target;
	this->_signed = signede;
	this->_grade_to_sign = g_s;
	this->_grade_to_exec = g_e;
}

void AForm::beSigned(const Bureaucrat& br)
{
	if (br.getGrade() > this->getSignGrade())
	{
		throw GradeTooLowException();
	}
	this->_signed = 1;
}

std::ostream& operator<<(std::ostream& os, AForm& fr)
{
    os << "form name: " << fr.getName() <<  ", grade required to sign: " << fr.getSignGrade() 
        << ", grade required to execute : " << fr.getExecGrade() << std::endl;
    return (os);
}


void AForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecGrade() < executor.getGrade() || this->getSignGrade() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();
	this->exec(executor);
}
