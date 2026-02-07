/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:40:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 10:42:29 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 42); 
        std::cout << bob.getName() << " created with grade " << bob.getGrade() << std::endl;
        std::cout << bob << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Caught high exception: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Caught low exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
    try {
        Bureaucrat alice("hunter", 1);
        alice.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Caught high exception: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Caught low exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
    try {
        Bureaucrat alice("Alice", 0);
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Caught high exception: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Caught low exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 200);
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Caught high exception: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Caught low exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues normally..." << std::endl;

    return 0;
}
