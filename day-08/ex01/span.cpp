#include "span.hpp"

Span::Span()
{}

Span::Span(unsigned int size): max_size(size)
{
    if(size < 1)
        throw SizeShouldBePositive();
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_size)
        throw NoSpaceLeft();
    numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin,
    std::vector<int>::iterator end)
{
    if (numbers.size() + std::distance(begin, end) > max_size)
        throw NoSpaceLeft();
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbers();

    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    int min_span = sorted_numbers[1] - sorted_numbers[0];
    for (size_t i = 1; i < sorted_numbers.size(); ++i)
    {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbers();
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    int min_number = sorted_numbers.front();
    int max_number = sorted_numbers.back();

    return max_number - min_number;
}

const char* Span::SizeShouldBePositive::what() const throw()
{
    return "Size should be positive.";
}

const char* Span::NoSpaceLeft::what() const throw()
{
    return "No space left to add more numbers.";
}

const char* Span::NotEnoughNumbers::what() const throw()
{
    return "Not enough numbers to calculate a span.";
}

