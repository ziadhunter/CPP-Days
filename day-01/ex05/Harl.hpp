/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:54:14 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/31 18:26:57 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        Harl() {}
        ~Harl() {}
        void complain(std::string level);
};


#endif