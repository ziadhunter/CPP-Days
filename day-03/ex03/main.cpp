/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:13:56 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/11 22:23:01 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "---- Creating DiamondTrap A ----" << std::endl;
    DiamondTrap a("Hunter");

    std::cout << "\n---- Creating DiamondTrap B (default then assign) ----" << std::endl;
    DiamondTrap b;
    b = a;

    std::cout << "\n---- Testing whoAmI() ----" << std::endl;
    a.whoAmI();
    b.whoAmI();

    std::cout << "\n---- Testing attack() ----" << std::endl;
    a.attack("enemy_robot");

    std::cout << "\n---- Testing energy/hit points operations ----" << std::endl;
    for (int i = 0; i < 3; i++)
        a.attack("dummy");

    std::cout << "\n---- End of scope ----" << std::endl;
    return 0;
}

