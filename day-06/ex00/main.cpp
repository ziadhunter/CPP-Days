/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:10:48 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/11 19:45:53 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    // std::string literal = argv[1];
    // char *end;
    // double value = strtod(literal.c_str(), &end);
    // int c = static_cast<int>(value);
    // std::cout << c << std::endl;
    return 0;
}