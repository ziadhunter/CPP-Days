/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:10:23 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 06:17:17 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", "unknown", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->set_attr(other.getName(), other.getTarget(),
                other.getIsSigned(), other.getSignGrade(), other.getExecGrade());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::exec() const
{
    std::cout << "* DRRRRRRRRRR DRILLING NOISES *" << std::endl;

    if (std::rand() % 2)
        std::cout << this->getTarget()
                  << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on "
                  << this->getTarget() << "!" << std::endl;
}