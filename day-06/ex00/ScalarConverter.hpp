#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

    public:
        static void convert(const std::string &input);
};

#endif