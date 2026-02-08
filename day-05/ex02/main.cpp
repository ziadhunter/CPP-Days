/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:40:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 07:15:30 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\n========== EX02 ALL FORMS TEST ==========\n";

    /* ===================================================== */
    std::cout << "\n========== SHRUBBERY CREATION FORM ==========\n";
    try
    {
        ShrubberyCreationForm shrub("garden");
        Bureaucrat signer("Signer", 130);
        Bureaucrat executor("Executor", 130);

        std::cout << shrub << std::endl;

        signer.signForm(shrub);
        executor.executeForm(shrub);

        std::cout << "Check file: garden_shrubbery\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Execute without signing ---\n";
        ShrubberyCreationForm shrub("park");
        Bureaucrat boss("Boss", 1);
        boss.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Sign with low grade ---\n";
        ShrubberyCreationForm shrub("home");
        Bureaucrat low("Low", 150);
        low.signForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    /* ===================================================== */
    std::cout << "\n========== ROBOTOMY REQUEST FORM ==========\n";
    try
    {
        RobotomyRequestForm robot("Bender");
        Bureaucrat signer("Signer", 70);
        Bureaucrat executor("Executor", 40);

        std::cout << robot << std::endl;

        signer.signForm(robot);

        for (int i = 0; i < 4; i++)
        {
            std::cout << "\n--- Robotomy attempt " << i + 1 << " ---\n";
            executor.executeForm(robot);
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Execute with low grade ---\n";
        RobotomyRequestForm robot("Wall-E");
        Bureaucrat signer("Signer", 1);
        Bureaucrat low("Low", 150);

        signer.signForm(robot);
        low.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    /* ===================================================== */
    std::cout << "\n========== PRESIDENTIAL PARDON FORM ==========\n";
    try
    {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat signer("Signer", 20);
        Bureaucrat president("President", 1);

        std::cout << pardon << std::endl;

        signer.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Sign with low grade ---\n";
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat low("Low", 150);

        low.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Execute without signing ---\n";
        PresidentialPardonForm pardon("Trillian");
        Bureaucrat boss("Boss", 1);

        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}



