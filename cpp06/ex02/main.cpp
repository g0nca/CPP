#include "Base.hpp"

int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::srand(time(NULL));
    Base* test1 = generate();

    delete test1;
    return (0);
};