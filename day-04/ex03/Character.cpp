// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Character.cpp                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/01/13 06:27:24 by zfarouk           #+#    #+#             */
// /*   Updated: 2026/01/13 16:10:29 by zfarouk          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "Character.hpp"

// Character::Character()
// {
//     this->_name = "unknown";
//     for (int i = 0; i < 4; i++)
//         this->_inventory[i] = NULL;
// }

// Character::Character(std::string name)
// {
//     this->_name = name;
//     for (int i = 0; i < 4; i++)
//         this->_inventory[i] = NULL;
// }
// Character::Character(const Character& other)
// {
//     *this = other;
// }

// Character& Character::operator=(const Character& other)
// {
//     if (this != &other)
//     {
//         this->_name = other._name;

//         for (int i = 0; i < 4; ++i)
//         {
//             if (this->_inventory[i])
//             {
//                 delete this->_inventory[i];
//                 this->_inventory[i] = NULL;
//             }
//             if (other._inventory[i])
//                 this->_inventory[i] = other._inventory[i]->clone();
//             else
//                 this->_inventory[i] = NULL;
//         }
//     }
//     return *this;
// }

// Character::~Character()
// {
//     for (int i = 0; i < 4; i++)
//     {
//         if (_inventory[i])
//             delete _inventory[i];
//     }
// }

// std::string const & Character::getName() const
// {
//     return (_name);
// }

// void Character::equip(AMateria* m)
// {
//     if (!m)
//         return;
//     for (int i = 0; i < 4; i++)
//     {
//         if (this->_inventory[i] == NULL)
//         {
//             this->_inventory[i] = m;
//             return;
//         }
//     }
// }

// void Character::unequip(int idx)
// {
//     if (idx < 0 || idx >= 4)
//         return;

//     if (this->_inventory[idx] == NULL)
//         return;
//     this->_inventory[idx] = NULL;
// }

// void Character::use(int idx, ICharacter& target)
// {
//     if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
//         return;
//     this->_inventory[idx]->use(target);
// }

// AMateria* Character::getMateria(int idx) const
// {
//     if (idx < 0 || idx >= 4)
//         return NULL;
//     return this->_inventory[idx];
// }

#include "Character.hpp"

Character::Character() : name("Player")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

Character::Character(const std::string& name) : name(name)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < 100; ++i)
		this->inventoryTrash[i] = NULL;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; ++i)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
		for (int i = 0; i < 100; ++i)
		{
			if (this->inventoryTrash[i])
			{
				delete this->inventoryTrash[i];
				this->inventoryTrash[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	this->clearInventoryTrash();
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Cannot equip NULL materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " materia to slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip materia" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (this->inventory[idx])
	{
		std::cout << "Unequipped " << this->inventory[idx]->getType() << " materia from slot " << idx << std::endl;
		this->addToTrash(this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
	else
		std::cout << "No materia to unequip in slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "No materia to use in slot " << idx << std::endl;
}

void Character::addToTrash(AMateria* m)
{
	for (int i = 0; i < 100; ++i)
	{
		if (this->inventoryTrash[i] == NULL)
		{
			this->inventoryTrash[i] = m;
			return;
		}
	}
}

void Character::clearInventoryTrash()
{
	std::cout << "clear inventory trash of  " << this->name << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		if (this->inventoryTrash[i])
		{
			delete this->inventoryTrash[i];
			this->inventoryTrash[i] = NULL;
		}
	}
}
