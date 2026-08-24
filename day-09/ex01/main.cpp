#include "Rpn.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << "Rpn <RPN expression>" << std::endl;
        return 1;
    }

    try {
        Rpn rpn(argv[1]);
    } catch (const Rpn::InvalidExpression& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
    