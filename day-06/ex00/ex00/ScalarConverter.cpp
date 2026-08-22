#include "ScalarConverter.hpp"

int handlePseudoLiterals(const std::string &input)
{
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input == "nan" || input == "+inf" || input == "-inf")
        {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        else
        {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        }
        return 1;
    }
    return 0;
}

int handleChar(const std::string &input)
{
    if (input.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return 1;
    }
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return 1;
    }
    return 0;
}

int handleInt(const std::string& input)
{
    char *end;
    double result = strtod(input.c_str(), &end);
    if (result > INT_MAX || result < INT_MIN || end[0] != '\0' || input.find('.') != std::string::npos)
        return 0;
    int intValue = atoi(input.c_str());
    if (intValue < 0 || intValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(intValue))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
    return 1;
}

int handleFloat(const std::string& input)
{
    //khasso ysali b f wfih fassila
    //maykonch fayt maxfloat wla min
    //ma3ndoch chi haja mora f
    char *end;
    double result = strtod(input.c_str(), &end);
    if (end[0] != 'f')
        return 0;
    if (result < -FLT_MAX || result > FLT_MAX || input.find('.') == std::string::npos 
         || end[1] != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: impossible" << std::endl; 
        std::cout << "double: impossible" << std::endl;
        return 1;
    }
    float flt = std::atof(input.c_str());
	
    if (flt < 0 || flt > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(flt))
        std::cout << "char: Non displayable" << std::endl;
    else
    {
        std::cout << "char: '" << static_cast<char>(flt) << "'" << std::endl;
    }

	if (flt > INT_MAX || flt < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(flt) << std::endl;
    
    // chi 7al lscientific notation
	std::cout << "float: " << flt;
    if (flt - std::floor(flt) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(flt);
    if (flt - std::floor(flt) == 0)
        std::cout << ".0";
    std::cout << std::endl;
	return 1;
	
    return 1;
}

int handledouble(const std::string &literal){
	char *end;

	double dbl = strtod(literal.c_str(), &end);
	if (((dbl == HUGE_VAL || dbl == -HUGE_VAL) && errno == ERANGE) || *end)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 1;
	}
	if (dbl < 0 || dbl > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(dbl))
        std::cout << "char: Non displayable" << std::endl;
    else
    {
        std::cout << "char: '" << static_cast<char>(dbl) << "'" << std::endl;
    }

	if (dbl > INT_MAX || dbl < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(dbl) << std::endl;
	if (dbl > FLT_MAX || dbl < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(dbl);
    	if (dbl - std::floor(dbl) == 0)
    	    std::cout << ".0";
    	std::cout << "f" << std::endl;
	}

	std::cout << "double: " << dbl;
    if (dbl - std::floor(dbl) == 0)
        std::cout << ".0";
    std::cout << std::endl;
    return 1;
}

void ScalarConverter::convert(const std::string &input)
{
    if (handlePseudoLiterals(input))
        std::cout << "Conversion completed for pseudo-literal";
    else if (handleChar(input))
        std::cout << "Conversion completed for char";
    else if (handleInt(input))
        std::cout << "Conversion completed for int";
    else if (handleFloat(input))
        std::cout << "Conversion completed for float";
    else if (handledouble(input))
        std::cout << "Conversion completed for double";
}


