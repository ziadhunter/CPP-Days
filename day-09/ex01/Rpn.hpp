#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <exception>

class Rpn {
private:
    std::stack<double> stack;
    Rpn();

public:
    Rpn(const std::string& expression);
    Rpn(const Rpn& other);
    Rpn& operator=(const Rpn& other);
    ~Rpn();
    void evaluate(const std::string& expression);
    void performOperation(const std::string& op);
    bool isNumber(const std::string& str);

    class InvalidExpression : public std::exception {
        std::string message;
        public:
            InvalidExpression(const std::string& msg);
            ~InvalidExpression() throw();
            const char* what() const throw();
    };
};

#endif