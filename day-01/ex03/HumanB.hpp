/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:11 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/31 15:13:36 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(std::string name): _name(name), _weapon(NULL) {};
        void setWeapon(Weapon& weapon);
        void attack();
        ~HumanB() {}
};


#endif