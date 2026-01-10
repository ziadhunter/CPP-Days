/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:13:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/10 17:19:30 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Hunter");
    ClapTrap b("Zombie");

    a.attack("Zombie");
    b.takeDamage(5);

    b.beRepaired(3);
    b.takeDamage(100);

    // Try to do things after death
    b.attack("Hunter");
    b.beRepaired(10);

    // Drain energy from a
    for (int i = 0; i < 12; i++)
        a.attack("Dummy target");

    // Try to repair with no energy
    a.beRepaired(5);

    return 0;
}