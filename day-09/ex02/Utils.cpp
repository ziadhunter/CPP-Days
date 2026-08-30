#include "Utils.hpp"

bool CompareFunction(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.second < b.second;
}


int isValidNumber(const std::string& str)
{
    size_t i = 0;

    if (str.empty())
    {
        throw NotValid("Error: empty arguement");
    }
    long number = 0;
    if (str[i] == '-')
    {
        throw NotValid("Error: negative number");
    }
    while (i < str.size())
    {
        if (!std::isdigit(str[i]))
            throw NotValid("Error: not a number");

        number = number * 10 + (str[i] - '0');
        if (number > INT_MAX)
            throw NotValid("Error: number is too large");

        i++;
    }
    return static_cast<int>(number);
}

std::vector<int> validateArguement(char **av, int ac)
{
    std::vector<int> args;
    args.reserve(ac - 1);
    int i = 1;
    while (i < ac)
    {
        args.push_back(isValidNumber(std::string(av[i])));
        i++;
    }
    return args;
}



NotValid::NotValid(std::string msg): message(msg) {}
NotValid::~NotValid() throw() {}
const char* NotValid::what() const throw()
{
    return (message.c_str());
}
