#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string     _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        
        std::string     getTarget() const;
        
        void    execute(Bureaucrat const &bureaucrat) const;
};

std::ostream    &operator<<(std::ostream &out, RobotomyRequestForm const &form);