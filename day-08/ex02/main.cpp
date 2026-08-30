#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     mstack.push(3);
//     mstack.push(42);
//     mstack.push(10);

//     std::cout << "Normal iterator:" << std::endl;

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::cout << std::endl;

//     std::cout << "Reverse iterator:" << std::endl;

//     MutantStack<int>::reverse_iterator rit = mstack.rbegin();
//     MutantStack<int>::reverse_iterator rite = mstack.rend();

//     while (rit != rite)
//     {
//         std::cout << *rit << std::endl;
//         ++rit;
//     }

//     std::cout << std::endl;

//     std::cout << "Top: " << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << "After pop, top: " << mstack.top() << std::endl;

//     std::cout << "Size: " << mstack.size() << std::endl;

//     return 0;
// }