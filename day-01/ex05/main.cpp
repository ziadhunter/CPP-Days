/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:53:55 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/31 18:25:16 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"  // Make sure this is the header for your Harl class

int main() {
    Harl harl;

    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n=== INFO ===" << std::endl;
    harl.complain("INFO");

    std::cout << "\n=== WARNING ===" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n=== ERROR ===" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n=== UNKNOWN ===" << std::endl;
    harl.complain("SOMETHING_ELSE"); // Test unknown level

    return 0;
}