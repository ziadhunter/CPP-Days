/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:48:18 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/14 02:18:17 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing Polymorphism ---\n";
    for (int i = 0; i < arraySize; ++i)
    {
        animals[i]->makeSound();
    }

    std::cout << "\n--- Proving Animal class is abstract ---" << std::endl;
    std::cout << "The following line is commented out, because it would cause a compile error:" << std::endl;
    std::cout << "// Animal* meta = new Animal();" << std::endl;
    // Animal* meta = new Animal(); // This line will cause a compile error

    std::cout << "\n--- Cleaning up ---" << std::endl;
    for (int i = 0; i < arraySize; ++i)
    {
        delete animals[i];
    }

    return 0;
}