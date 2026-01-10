/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:08:33 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/06 22:24:56 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return a;
    return b;
}

Fixed& Fixed::operator++()
{
    this->_fixedPointValue += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue += 1;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue -= 1;
    return tmp;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->toFloat() > other.toFloat() || this->toFloat() == other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->toFloat() < other.toFloat() || this->toFloat() == other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();

    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

Fixed::Fixed(const int n)
{
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (1 << _fractionalBits));
}

