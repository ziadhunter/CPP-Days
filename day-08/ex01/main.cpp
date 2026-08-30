#include "span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== 1. SUBJECT DEFAULT TEST ===" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. EXCEPTION TESTS ===" << std::endl;

    try
    {
        std::cout << "Testing overflow addition: ";
        Span spFull(2);
        spFull.addNumber(1);
        spFull.addNumber(2);
        spFull.addNumber(3);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught -> " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing span calculation with 1 element: ";
        Span spOne(5);
        spOne.addNumber(42);
        spOne.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught -> " << e.what() << std::endl;
    }

    std::cout << "\n=== 3. NEGATIVE NUMBERS ===" << std::endl;
    try
    {
        Span spNeg(5);
        spNeg.addNumber(-20);
        spNeg.addNumber(-6);
        spNeg.addNumber(0);
        spNeg.addNumber(10);
        spNeg.addNumber(-5);

        std::cout << "Shortest Span : " << spNeg.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << spNeg.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== 4. RANGE INSERTION & LARGE DATASET (10,000+ numbers) ===" << std::endl;
    try
    {
        unsigned int N = 15000;
        Span spLarge(N);

        std::vector<int> randomNumbers;
        randomNumbers.reserve(N);

        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (unsigned int i = 0; i < N; ++i)
            randomNumbers.push_back(std::rand());

        spLarge.addNumber(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "Shortest Span: " << spLarge.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << spLarge.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== 5. COPY CONSTRUCTOR & ASSIGNMENT OPERATOR ===" << std::endl;
    try
    {
        Span original(3);
        original.addNumber(100);
        original.addNumber(200);
        original.addNumber(300);

        Span copyConst(original);
        Span assigned = original;

        std::cout << "Original Longest Span: " << original.longestSpan() << std::endl;
        std::cout << "CopyConst Longest Span: " << copyConst.longestSpan() << std::endl;
        std::cout << "Assigned Longest Span:  " << assigned.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}