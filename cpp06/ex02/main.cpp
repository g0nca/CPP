#include "Base.hpp"
#include "Utils.hpp"

int     main(int ac, char **av)
{
    std::srand(time(NULL));
    try
    {
        int timesToRun = 0;
        if (ac != 3)
            throw (Utils::MissingArguments());
        timesToRun = std::atoi(av[2]);
        if (timesToRun < 0)
            throw (Utils::NegativeNumber());

        std::string mode = av[1];

        if (timesToRun > 0 && mode == "pointer")
        {
            int count = 0;
            while (count < timesToRun)
            {
                Base* test1 = generate();
                identify(test1);
                delete test1;
                count++;
            }
        }
        else if (timesToRun > 0 && mode == "reference")
        {
            int count = 0;
            while (count < timesToRun)
            {
                Base* test2 = generate();
                identify(*test2);
                delete test2;
                count++;
            }
        }
        else
            throw (Utils::WrongArguments());
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
};