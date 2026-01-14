/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 03:56:59 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/13 04:49:13 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {};

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & other) : _type(other._type) {}

AMateria & AMateria::operator=(AMateria const & other)
{
    if (this != &other)
        _type = other._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
