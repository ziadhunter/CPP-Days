/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:12:12 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/31 15:27:25 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon() {};
        Weapon(std::string name): _type(name) {};
        std::string& getType();
        void setType(std::string name);
        ~Weapon() {};
};

#endif