/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Array.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:18:55 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/13 19:54:09 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP

#include <exception>

template <typename T>
class Array {
    private:
        T *row;
        unsigned int len;
    public:
        Array();
        Array(unsigned int len);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;

    unsigned int size() const;

    class OutOfRangeException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of range";
        }
    };
};

#include "Array.tpp"

#endif