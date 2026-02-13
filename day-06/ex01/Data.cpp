/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:36:52 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 22:39:03 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): value(0) {}

Data::Data(int num): value(num) {}

Data::Data(const Data& other)
{
    *this = other;
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
    }
    return *this;
}

Data::~Data() {}
