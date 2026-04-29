#include "Base.hpp"

Base::~Base(){};

Base*     generate(void)
{
    int     random = rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
    return (NULL);
};

void    identify(Base* p)
{
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "* -> Pointer to A" << std::endl;
    else if (B *b = dynamic_cast<B*>(p))
        std::cout << "* -> Pointer to B" << std::endl;
    else if (C *c = dynamic_cast<C*>(p))
        std::cout << "* -> Pointer to C" << std::endl;

};

void    identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "& -> Reference to A " << std::endl;
    }
    catch (std::exception &e) { };
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "& -> Reference to B" << std::endl;

    }
    catch (std::exception &e) { };
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "& -> Reference to C" << std::endl;
    }
    catch (std::exception &e) { };
};