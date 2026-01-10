/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:22:05 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/11 00:50:05 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->_name = "unknown";
    this->_AttackDamage = 0;
    this->_EnergyPoint = 10;
    this->_HitPoint = 10;
}
ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
    this->_AttackDamage = 0;
    this->_EnergyPoint = 10;
    this->_HitPoint = 10;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "copy constructor called" << std::endl;
    this->_name = other._name;
    this->_HitPoint = other._HitPoint;
    this->_EnergyPoint = other._EnergyPoint;
    this->_AttackDamage = other._AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_HitPoint = other._HitPoint;
        this->_EnergyPoint = other._EnergyPoint;
        this->_AttackDamage = other._AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;    
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_EnergyPoint > 0 && this->_HitPoint > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
        this->_EnergyPoint--;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " cannot attack due to insufficient energy or hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    if (this->_HitPoint == 0)
        return;
    if (amount >= this->_HitPoint)
        this->_HitPoint = 0;
    else
        this->_HitPoint -= amount; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPoint > 0 && this->_HitPoint > 0)
    {
        std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
        this->_HitPoint += amount;
        this->_EnergyPoint--;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " cannot be repaired due to insufficient energy or hit points." << std::endl;
}