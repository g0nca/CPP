#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>

template <typename T>
typename T::iterator    easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    
    return (it);
};

template <typename T>
typename T::const_iterator    easyfind(const T& container, int value)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    
    return (it);
};

