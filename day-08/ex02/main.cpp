#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(42);
    mstack.push(10);

    std::cout << "Normal iterator:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Reverse iterator:" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << std::endl;

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "After pop, top: " << mstack.top() << std::endl;

    std::cout << "Size: " << mstack.size() << std::endl;

    return 0;
}