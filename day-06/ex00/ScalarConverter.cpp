/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:00:33 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/12 17:24:47 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
    {
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

LiteralType detectType(const std::string& literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    	return FLOAT_TYPE;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    	return DOUBLE_TYPE;
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    	return CHAR_TYPE;
    char* end;
    double value = strtod(literal.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
    	return FLOAT_TYPE;
    else if (*end == '\0' && (literal.find('.') != std::string::npos ||
    		value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)))
    	return DOUBLE_TYPE;
    else if (*end == '\0')
    	return INT_TYPE;
    return INVALID_TYPE;
}
void isvalidchar(double value)
{
    if ((std::isnan(value) || std::isinf(value)) || (value < 0 || value > 127))
    	throw Impossible();
    else if (!std::isprint(static_cast<unsigned char>(value)))
    	throw NotDisplayable();
}

void print_char(double value)
{
    try
    {
        isvalidchar(value);
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: " << e.what() << '\n';
    }
}

void isvalidint(double value)
{
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)
        || std::isnan(value) || std::isinf(value))
        throw Impossible();
}

void print_int(double value)
{
    try
    {
        isvalidint(value);
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "int: " << e.what() << '\n';
    }
}

void print_float(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << std::setprecision(1) << std::fixed << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void print_double(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "double: " << value << std::endl;
    else
        std::cout << std::setprecision(1) << "double: " << value << std::endl;
}

void handle_char(char c)
{
	try
    {
        isvalidchar(static_cast<double>(c));
        std::cout << "char: '" << c << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: " << e.what() << '\n';
    }
	double value = static_cast<double>(c);
	print_int(value);
	print_float(value); 
	print_double(value);
} 
void handle_int(std::string literal)

{
    int i = atoi(literal.c_str());
    double value = static_cast<double>(i);
    print_char(value);
    print_int(value);
    print_float(value);
    print_double(value);
}

void handle_float(const std::string& literal)
{
    float f = strtof(literal.c_str(), NULL);
    double value = static_cast<double>(f);

    print_char(value);
    print_int(value);
    print_float(f);
    print_double(value);
}

void handle_double(const std::string& literal)
{
    double value = strtod(literal.c_str(), NULL);

    print_char(value);
    print_int(value);
    print_float(value);
    print_double(value);
}


void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    if (type == INVALID_TYPE)
    {
        std::cout << "Invalid literal\n";
        return;
    }
    switch (type)
    {
        case CHAR_TYPE:
            handle_char(static_cast<char>(literal[0]));
			std::cout << "char";
            break;
        case INT_TYPE:
            handle_int(literal);
			std::cout << "int";
            break;
        case FLOAT_TYPE:
			std::cout << "float";
            handle_float(literal);
            break;
        case DOUBLE_TYPE:
			std::cout << "double";
            handle_double(literal);
            break;
        default:
            break;
    }
}











// void ScalarConverter::convert(const std::string& literal)
// {
//     double value;
//     if (literal.length() == 1 && !std::isdigit(literal[0]))
//     {
//         value = static_cast<double>(literal[0]);
//         print_char(value);
//         print_int(value);
//         print_float(value);
//         print_double(value); 
//         return;
//     }
//     char *end;
//     value = strtod(literal.c_str(), &end);
//     bool valid = false;
//     if (*end == '\0')
//         valid = true;
//     else if (end[0] == 'f' && end[1] == '\0')
//         valid = true;
//     if (!valid)
//     {
//         std::cout << "Invalid literal\n";
//         return;
//     }
//     print_char(value);
//     print_int(value);
//     print_float(value);
//     print_double(value);
// }