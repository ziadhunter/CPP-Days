/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:17:53 by zfarouk           #+#    #+#             */
/*   Updated: 2026/01/07 23:10:09 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point A, Point B, Point C, Point P) {
    Fixed d1 = (B.getX() - A.getX()) * (P.getY() - A.getY()) - (B.getY() - A.getY()) * (P.getX() - A.getX());
    Fixed d2 = (C.getX() - B.getX()) * (P.getY() - B.getY()) - (C.getY() - B.getY()) * (P.getX() - B.getX());
    Fixed d3 = (A.getX() - C.getX()) * (P.getY() - C.getY()) - (A.getY() - C.getY()) * (P.getX() - C.getX());

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
} 