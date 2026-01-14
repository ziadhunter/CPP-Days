/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 07:08:41 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/14 02:15:41 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : count(0)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
    count = other.count;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < 4; ++i)
    {
        delete materias[i];
        materias[i] = NULL;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
    }

    count = other.count;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    if (count >= 4)
    {
        delete m;
        return;
    }
    materias[count++] = m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}
