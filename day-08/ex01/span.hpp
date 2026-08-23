#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int max_size;
        Span();

    public:
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin,
            std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class SizeShouldBePositive : public std::exception 
        {
            const char* what() const throw();
        };

        class NoSpaceLeft : public std::exception 
        {
            const char* what() const throw();
        };

        class NotEnoughNumbers : public std::exception 
        {
            const char* what() const throw();
        };

};

#endif