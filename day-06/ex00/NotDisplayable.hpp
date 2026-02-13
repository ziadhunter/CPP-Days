/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotDisplayable.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:50:00 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 12:26:18 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTDISPLAYABLE_HPP
#define NOTDISPLAYABLE_HPP

#include <exception>

enum LiteralType
{
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    INVALID_TYPE
};

class NotDisplayable : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Non displayable";
        }
};

#endif