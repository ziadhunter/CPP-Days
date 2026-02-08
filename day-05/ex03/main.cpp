/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:40:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/08 08:05:12 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(NULL)); // for Robotomy randomness

    std::cout << "\n========== EX02: INTERN & FORMS TEST ==========\n";

    Intern someRandomIntern;

    /* ----------------- SHRUBBERY CREATION ----------------- */
    std::cout << "\n--- Test 1: Shrubbery Creation Form ---\n";
    try
    {
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
        Bureaucrat signer("Alice", 140);
        Bureaucrat executor("Bob", 140);

        signer.signForm(*shrub);
        executor.executeForm(*shrub);

        delete shrub;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    /* ----------------- ROBOTOMY REQUEST ----------------- */
    std::cout << "\n--- Test 2: Robotomy Request Form ---\n";
    try
    {
        AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat signer("Charlie", 70);
        Bureaucrat executor("David", 45);

        signer.signForm(*robot);
        // test multiple times to see randomness
        for (int i = 0; i < 4; i++)
        {
            std::cout << "\n--- Robotomy attempt " << i + 1 << " ---\n";
            executor.executeForm(*robot);
        }

        delete robot;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    /* ----------------- PRESIDENTIAL PARDON ----------------- */
    std::cout << "\n--- Test 3: Presidential Pardon Form ---\n";
    try
    {
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        Bureaucrat signer("Eve", 20);
        Bureaucrat president("Frank", 1);

        signer.signForm(*pardon);
        president.executeForm(*pardon);

        delete pardon;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    /* ----------------- INVALID FORM TEST ----------------- */
    std::cout << "\n--- Test 4: Invalid form ---\n";
    AForm* invalid = someRandomIntern.makeForm("unknown form", "Target");
    if (!invalid)
        std::cout << "Correctly handled invalid form.\n";

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}

