/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 03:40:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/07 14:14:37 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void print_separator() {
    std::cout << "----------------------------------------" << std::endl;
}

int main()
{
    print_separator();
    std::cout << "TEST 1: Creating forms with valid and invalid grades" << std::endl;

    try {
        Form f1("FormA", 1, 1); // valid
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form f2("FormB", 0, 1); // grade too high
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form f3("FormC", 151, 1); // grade too low
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    print_separator();
    std::cout << "TEST 2: Bureaucrat signing forms" << std::endl;

    Bureaucrat b1("Alice", 1);    // highest grade
    Bureaucrat b2("Bob", 50);     // mid grade
    Bureaucrat b3("Charlie", 150); // lowest grade

    Form f4("TopSecret", 1, 1);   // needs grade 1 to sign
    Form f5("Report", 50, 50);    // needs grade 50 to sign
    Form f6("Routine", 100, 100); // needs grade 100 to sign

    // Test signing success
    b1.signForm(f4); // Alice can sign TopSecret
    b2.signForm(f5); // Bob can sign Report

    // Test signing failure
    b2.signForm(f4); // Bob cannot sign TopSecret
    b3.signForm(f6); // Charlie cannot sign Routine

    print_separator();
    std::cout << "TEST 3: Printing forms status" << std::endl;

    std::cout << f4 << std::endl;
    std::cout << f5 << std::endl;
    std::cout << f6 << std::endl;

    print_separator();
    std::cout << "TEST 4: Bureaucrats with invalid grades" << std::endl;

    try {
        Bureaucrat invalidBureaucrat("Dave", 0); // too high
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidBureaucrat2("Eve", 151); // too low
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    print_separator();
    return 0;
}

