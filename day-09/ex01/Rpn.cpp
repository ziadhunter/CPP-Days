#include "Rpn.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const std::string& expression) {
    evaluate(expression);
}

Rpn::Rpn(const Rpn& other) {
    stack = other.stack;
}

Rpn& Rpn::operator=(const Rpn& other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

Rpn::~Rpn() {}

bool Rpn::isNumber(const std::string& str) {
    if ((str.size() == 1 && std::isdigit(str[0])) || (str.size() == 2 && str[0] == '-' && std::isdigit(str[1]))) {
        return true;
    }
    if (str.size() >= 2) {
        throw InvalidExpression("invalid number: " + str);
    }
    return false;
}

void Rpn::performOperation(const std::string& op) {
    if (op != "+" && op != "-" && op != "*" && op != "/") {
        throw InvalidExpression("Unknown operator: " + op);
    }

    if (stack.size() < 2) {
        throw InvalidExpression("operation: " + op + " requires at least two numbers");
    }

    double b = stack.top();
    stack.pop();
    double a = stack.top();
    stack.pop();
    double result;

    if (op == "+") {
        result = a + b;
    } else if (op == "-") {
        result = a - b;
    } else if (op == "*") {
        result = a * b;
    } else if (op == "/") {
        if (b == 0) {
            throw InvalidExpression("Division by zero");
        }
        result = a / b;
    } else {
        throw InvalidExpression("Unknown number or operator: " + op);
    }
    stack.push(result);
}

void Rpn::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isNumber(token)) {
            int number;
            std::stringstream(token) >> number;
            stack.push(number);
        } else {
            performOperation(token);
        }
    }

    if (stack.size() != 1) {
        throw InvalidExpression("Invalid RPN expression");
    }

    std::cout  << stack.top() << std::endl;
}

Rpn::InvalidExpression::InvalidExpression(const std::string& msg) : message(msg) {}

Rpn::InvalidExpression::~InvalidExpression() throw()  {}

const char* Rpn::InvalidExpression::what() const throw() {
    return message.c_str();
}