/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:49:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 17:13:07 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    private:
		std::string _name;
		std::string _target;
		bool		_signed;
		int			_grade_to_sign;
		int			_grade_to_exec;
	public:
		AForm();
		AForm(std::string name, std::string AForm, int sign_grad, int exec_grad);
		AForm(const AForm& other);
		~AForm();
		AForm& operator=(const AForm& other);
		const std::string& getName() const;
		const std::string& getTarget() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat& br);
		virtual void execute(Bureaucrat const & executor) = 0;
		void set_attr(std::string name, std::string target, bool signede, int g_s, int g_e);
		
		
		
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

std::ostream& operator<<(std::ostream& os, AForm& fr);

#endif