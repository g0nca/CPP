#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
    std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat: Name Constructor Called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
    std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
};

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &copy){
    if (this != &copy)
    {
        _grade = copy._grade;
        std::cout << "Bureaucrat: Assignment Operator Called" << std::endl;
    }
    return (*this);
};

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat: Desctructor Called" << std::endl;
};


std::string     Bureaucrat::getName() const {
    return (_name);
};

int             Bureaucrat::getGrade() const {
    return (_grade);
};

void            Bureaucrat::incrementBureaucrat(){
    this->_grade++;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
};

void            Bureaucrat::decrementBureaucrat(){
    this->_grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
};

void            Bureaucrat::signForm(AForm &form) {
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;  
    }
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}