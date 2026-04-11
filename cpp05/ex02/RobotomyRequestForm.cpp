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

std::ostream    &operator<<(std::ostream &out, RobotomyRequestForm &form) {
        out << "RobotomyRequestForm : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.isSigned() << std::endl;
        return (out);
};
