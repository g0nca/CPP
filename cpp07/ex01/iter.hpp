#pragma once


#include <string>
#include <iostream>

template <typename T, typename Func>
void   iter(T *array, size_t length, Func f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void    incrementValue(T& value)
{
    value += 1;
}

template <typename T>
void    printValue(const T& value)
{
    std::cout << value << " ";  
}