// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Character.hpp                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/01/13 05:12:18 by zfarouk           #+#    #+#             */
// /*   Updated: 2026/01/13 06:27:58 by zfarouk          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef CHARACTER_HPP
// #define CHARACTER_HPP

// #include "ICharacter.hpp"
// #include "AMateria.hpp"

// class Character : public ICharacter
// {
//     private:
//         std::string _name;
//         AMateria* _inventory[4];
//     public:
//         Character();
//         Character(std::string name);
//         Character(const Character& other);
//         Character& operator=(const Character& other);
//         ~Character();

//         std::string const & getName() const;
//         void equip(AMateria* m);
//         void unequip(int idx);
//         void use(int idx, ICharacter& target);
//         AMateria* getMateria(int idx) const;
// };



// #endif

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		AMateria* inventoryTrash[100];

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void addToTrash(AMateria* m);
		void clearInventoryTrash();
};

#endif 