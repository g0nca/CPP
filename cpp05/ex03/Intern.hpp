#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public :
        Intern(void);
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern(void);

        AForm *makeForm(std::string formName, std::string target);
};