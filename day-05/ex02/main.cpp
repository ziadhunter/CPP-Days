/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:40:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 19:27:38 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "========== SHRUBBERY CREATION FORM TESTS ==========\n";

    try
    {
        std::cout << "\n--- Test 1: Valid creation ---\n";
        ShrubberyCreationForm form("garden");
        std::cout << form << std::endl;

        std::cout << "\n--- Test 2: Sign with sufficient grade ---\n";
        Bureaucrat alice("Alice", 100);
        alice.signForm(form);

        std::cout << "\n--- Test 3: Execute with sufficient grade ---\n";
        Bureaucrat bob("Bob", 100);
        bob.executeForm(form);
        std::cout << "Check for file: garden_shrubbery\n";

    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 4: Sign with LOW grade (should fail) ---\n";
        ShrubberyCreationForm form("home");
        Bureaucrat tom("Tom", 150);
        tom.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 5: Execute WITHOUT signing ---\n";
        ShrubberyCreationForm form("park");
        Bureaucrat boss("Boss", 1);
        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- Test 6: Execute with LOW grade executor ---\n";
        ShrubberyCreationForm form("office");
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 150);

        signer.signForm(form);
        executor.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}


