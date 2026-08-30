#ifndef EasyFind_HPP
#define EasyFind_HPP

#include <algorithm>
#include <iterator>
#include <exception>


class NotFound : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "couldn't find an occurrence!";
        }
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int find)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end())
        throw NotFound();
    return it;
}

template <typename T>
typename T::iterator easyfind(T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end())
        throw NotFound();
    return it;
};

#endif