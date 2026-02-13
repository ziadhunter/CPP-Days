/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Impossible.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:53:25 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 11:54:25 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPOSSIBLE_HPP
#define IMPOSSIBLE_HPP

#include <exception> 

class Impossible : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Impossible";
        }
};


#endif