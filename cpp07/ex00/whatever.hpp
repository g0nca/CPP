#pragma once

#include <string>
#include <iostream>

template <typename T>void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

template <typename T>T min(T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}