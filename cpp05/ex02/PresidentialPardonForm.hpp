#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string     _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm& copy);

        std::string     getTarget() const;

        void    execute(const Bureaucrat& target) const;
};

std::ostream    &operator<<(std::ostream &out, PresidentialPardonForm const &form);