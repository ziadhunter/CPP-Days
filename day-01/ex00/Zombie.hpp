/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:58:25 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/30 19:06:22 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
        void announce(void);
        Zombie() {};
        Zombie(std::string name) : _name(name) {};
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif