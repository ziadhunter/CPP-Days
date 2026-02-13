/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:42:09 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 22:42:28 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"


int main() {
    Data d;
    d.value = 42;

    Data* originalPtr = &d;

    // Serialize
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << raw << std::endl;

    // Deserialize
    Data* newPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized value: " << newPtr->value << std::endl;

    // Check if pointers are equal
    if (originalPtr == newPtr)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers do not match!" << std::endl;

    return 0;
}
