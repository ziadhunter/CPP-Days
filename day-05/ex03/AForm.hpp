/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:49:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 07:59:41 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class AForm {
    private:
		std::string _name;
		std::string _target;
		bool		_signed;
		int			_grade_to_sign;
		int			_grade_to_exec;
	public:
		AForm();
		AForm(std::string name, std::string target, int sign_grad, int exec_grad);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);
		const std::string& getName() const;
		const std::string& getTarget() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
		void set_attr(std::string name, std::string target, bool signede, int g_s, int g_e);
		
		void beSigned(const Bureaucrat& br);
		void execute(Bureaucrat const & executor) const;
		virtual void exec() const = 0;
		
		class GradeTooHighException : public  std::exception {
			public:
				const char *what() const throw()
				{
					return "Grade is too high";
				}
		};
		
		class GradeTooLowException : public  std::exception {
			public:
				const char *what() const throw()
				{
						return "Grade is too low";
				}
		};
		
				class FormNotSignedException : public  std::exception {
			public:
				const char *what() const throw()
				{
					return "this form is not signed yet";
				}
		};
};

std::ostream& operator<<(std::ostream& os, AForm& fr);

#endif