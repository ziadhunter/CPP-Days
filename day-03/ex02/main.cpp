/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:13:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/11 17:49:01 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating ScavTrap objects ===\n";
    FragTrap s1;
    FragTrap s2("Hunter");
    
    std::cout << "\n=== Testing attack() ===\n";
    s1.attack("Target1");
    s2.attack("Target2");
    
    std::cout << "\n=== Testing highFivesGuys() ===\n";
    s1.highFivesGuys();
    s2.highFivesGuys();
    
    std::cout << "\n=== Testing copy constructor ===\n";
    FragTrap s3(s2);
    s3.attack("Target3");
    
    std::cout << "\n=== Testing assignment operator ===\n";
    s1 = s3;
    s1.attack("Target4");
    
    std::cout << "\n=== All objects will now be destroyed ===\n";
    
    return 0;
}
