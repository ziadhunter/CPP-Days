/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:40:36 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/30 18:52:31 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    randomChump("john");
    Zombie* zombie1 = newZombie("ziad");
    zombie1->announce();
    delete zombie1;
    return 0;
}