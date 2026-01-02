/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:25:06 by zfarouk           #+#    #+#             */
/*   Updated: 2025/12/31 17:44:56 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << "filename string1 string2" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream filecontent(filename.c_str());
    if (!filecontent)
    {
        std::cout << "Error: could not open file " << filename << std::endl;
        return 1;
    }
    std::string content;
    std::string line;
    while (std::getline(filecontent, line))
    {
        content += line;
        content += '\n';                  
    }
    size_t pos = 0;
    pos = content.find(s1, pos);
    while (pos != std::string::npos) { 
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
        pos = content.find(s1, pos);
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cout << "Error: could not create output file" << std::endl;
        return 1;
    }
    outfile << content;
    filecontent.close();
    outfile.close();
    return 0;
}