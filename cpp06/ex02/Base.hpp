#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <unistd.h>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);