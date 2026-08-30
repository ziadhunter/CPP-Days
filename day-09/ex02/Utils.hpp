#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <climits>
#include <cctype>

class NotValid : public std::exception
{
    private:
        std::string message;
    public:
        NotValid(std::string message);
        ~NotValid() throw();
        const char *what() const throw();
};


std::vector<int> validateArguement(char **av, int ac);
int isValidNumber(const std::string& str);
bool CompareFunction(std::pair<int, int> a, std::pair<int, int> b);

#endif