/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:14:02 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/12 21:33:35 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Template_HPP
#define Template_HPP

template <typename T>
void swap(T& first, T& second)
{
    T tmp;
    tmp = second;
    second = first;
    first = tmp;
}

template <typename T>
const T& min(const T& first, const T& second)
{
    if (second <= first)
        return second;
    return first;
}

template <typename T>
const T& max(const T& first, const T& second)
{
    if (second >= first)
        return second;
    return first;
}

#endif