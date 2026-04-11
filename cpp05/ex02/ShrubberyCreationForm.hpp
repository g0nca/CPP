#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string     _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        std::string     getTarget() const;
        void    execute(Bureaucrat const &bureaucrat) const;
};

std::ostream    &operator<<(std::ostream &out, ShrubberyCreationForm &form);