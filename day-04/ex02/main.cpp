/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:48:18 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/13 01:50:39 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

int main()
{
    const int arraySize = 4;
    AAnimal* meta = new AAnimal();

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

    std::cout << "\n--- Testing Deep Copy ---\n";
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Original Idea");

    Dog* copyDog = new Dog(*originalDog);

    std::cout << "Original Dog's first idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's first idea: " << copyDog->getBrain()->getIdea(0) << std::endl;

    std::cout << "--- Modifying copied dog's brain ---\n";
    copyDog->getBrain()->setIdea(0, "New Idea");

    std::cout << "Original Dog's first idea after modification: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's first idea after modification: " << copyDog->getBrain()->getIdea(0) << std::endl;

    if (originalDog->getBrain() != copyDog->getBrain())
        std::cout << "Brains are at different memory addresses (Correct Deep Copy)!" << std::endl;
    else
        std::cout << "Brains are at the same memory address (Incorrect Shallow Copy)!" << std::endl;

    delete originalDog;
    delete copyDog;

    for (int i = 0; i < arraySize; ++i)
    {
        delete animals[i];
    }

    return 0;
}