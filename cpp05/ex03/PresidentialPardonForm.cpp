#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Default", 25, 5), _target("Default") {
    std::cout << "Presidential : Default Constructor" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Presidential : Name Constructor" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target) {
    std::cout << "Presidential : Copy Constructor" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential : Destructor" << std::endl;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Presidential : Assginment Operator" << std::endl;
    }
    return (*this);
};

std::string     PresidentialPardonForm::getTarget() const {
    return (this->_target);
};

void    PresidentialPardonForm::execute(const Bureaucrat& target) const {
    try {
        if (!getIsSigned())
            throw FormNotSignedException();
        if (target.getGrade() > this->getExecute())
            throw GradeTooLowException();
        std::cout << target.getName() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
};

std::ostream    &operator<<(std::ostream &out, const PresidentialPardonForm &form) {
        out << "Presidential : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
        return (out);
};