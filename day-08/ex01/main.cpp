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

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected: 2 (9 - 11 or 17 - ...) -> (11 - 9 = 2)
        std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;  // Expected: 14 (17 - 3)
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. EXCEPTION TESTS ===" << std::endl;
    
    // Exception: Capacity 0
    try
    {
        std::cout << "Testing 0 size initialization: ";
        Span sp0(0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught -> " << e.what() << std::endl;
    }

    // Exception: Adding beyond capacity
    try
    {
        std::cout << "Testing overflow addition: ";
        Span spFull(2);
        spFull.addNumber(1);
        spFull.addNumber(2);
        spFull.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught -> " << e.what() << std::endl;
    }

    // Exception: Calculating span with 0 or 1 element
    try
    {
        std::cout << "Testing span calculation with 1 element: ";
        Span spOne(5);
        spOne.addNumber(42);
        spOne.shortestSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught -> " << e.what() << std::endl;
    }

    std::cout << "\n=== 3. NEGATIVE NUMBERS & DUPLICATES ===" << std::endl;
    try
    {
        Span spNeg(5);
        spNeg.addNumber(-20);
        spNeg.addNumber(-5);
        spNeg.addNumber(0);
        spNeg.addNumber(10);
        spNeg.addNumber(-5); // Duplicate

        std::cout << "Shortest Span (with duplicate -5): " << spNeg.shortestSpan() << std::endl; // Expected: 0
        std::cout << "Longest Span (-20 to 10): " << spNeg.longestSpan() << std::endl;         // Expected: 30
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

        // Using iterator range insert
        spLarge.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Successfully added " << N << " numbers via iterators." << std::endl;
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