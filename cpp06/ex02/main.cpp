#include "Base.hpp"

int     main(void)
{
    std::srand(time(NULL));
    Base* test1 = generate();

    delete test1;
    return (0);
};