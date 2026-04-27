#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

class   Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer& );
        Serializer& operator=(Serializer& copy);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};