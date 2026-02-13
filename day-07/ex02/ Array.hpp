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


template <typename T>
class Array {
    privete:
        T *row;
        Unsigned int len;
    public:
        Array(): row(nullptr), len(0) {};
        Array(undigned int len)
        {
            row = new T[n]();
        }
        Array(const Array& other) : row(new T[other.size]()), len(other.getlen())
        {
            this = other;
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] row;
                row = new T[other.len];
                len = other.len;
                for (int i)
            }
        }
        ~Array();
};

#endif