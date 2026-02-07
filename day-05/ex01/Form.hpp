/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:49:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 14:09:27 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
		std::string _name;
		bool		_signed;
		int			_grade_to_sign;
		int			_grade_to_exec;
	public:
		Form();
		Form(std::string name, int sign_grad, int exec_grad);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);
		const std::string& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat& br);
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
};

std::ostream& operator<<(std::ostream& os, Form& fr);

#endif