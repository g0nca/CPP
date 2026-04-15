#pragma once
#include "AForm.hpp"

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
std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &form);
