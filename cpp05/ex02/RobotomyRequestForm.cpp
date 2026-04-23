#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default", 72, 45), _target("Default") {
        std::cout << "Robotomy : Default Constructor" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
        std::cout << "Robotomy : Name Constructor" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
        std::cout << "Robotomy : Copy Constructor" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm() {
        std::cout << "Robotomy : Destructor"<< std::endl;
};

RobotomyRequestForm     &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
        if (this != &copy)
        {
                AForm::operator=(copy);
                _target = copy._target;
                std::cout << "Robotomy : Assignment Operator" << std::endl;
        }
        return (*this);
};

std::string     RobotomyRequestForm::getTarget() const {
        return (this->_target);
};

void    RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const 
{
        try {
                if (!getIsSigned())
                        throw FormNotSignedException();
                if (bureaucrat.getGrade() > this->getExecute())
                        throw GradeTooLowTooExecute();
                std::srand(std::time(NULL));
                std::cout << "BZZZZZ... drilling noises" << std::endl;
                if(rand() % 2 == 0)
                {
                        std::cout << _target << " has been robotomized sucessfully" << std::endl;
                }
                else
                {
                        std::cout << _target << " robotomized Failed ! " << std::endl;
                }
        }
        catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
                throw (AForm::GradeTooLowTooExecute());
        }
};


std::ostream    &operator<<(std::ostream &out, RobotomyRequestForm const &form) {
        out << "RobotomyRequestForm : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
        return (out);
};
