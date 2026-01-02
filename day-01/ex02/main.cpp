/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:40:36 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/30 20:04:39 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of str:       " << &str << std::endl;
    std::cout << "Address held by PTR:  " << stringPTR << std::endl;
    std::cout << "Address held by REF:  " << &stringREF << std::endl;
    std::cout << std::endl << std::endl;  
    std::cout << "Value of str:                    " << str << std::endl;
    std::cout << "The value pointed to by stringPTR" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF" << stringREF << std::endl;

    return 0;
}
