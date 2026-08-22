/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:24:04 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/12 22:30:37 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    Array<int> numbers(3);
    std::cout << "Initial value: " << numbers[0] << std::endl;

    Array<std::string> words(2);
    words[0] = "Hello";
    words[1] = "World";
    std::cout << words[0] << " " << words[1] << std::endl;

    Array<int> copy(numbers);
    numbers[0] = 42;
    std::cout << "Original: " << numbers[0] << " | Copy: " << copy[0] << std::endl;

    try {
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}