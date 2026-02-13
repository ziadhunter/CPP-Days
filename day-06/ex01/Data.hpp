/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:33:53 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 22:43:00 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data {
    public:
        int value;
        Data();
        Data(int num);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
};

#endif