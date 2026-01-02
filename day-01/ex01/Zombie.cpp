/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:52:41 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/30 18:56:20 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
    Zombie new_zombie(name);
    new_zombie.announce();
}

Zombie* newZombie( std::string name )
{
    Zombie* new_zombie = new Zombie(name);
    return new_zombie;
}
