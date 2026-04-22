#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137), _target("Default")
{
    std::cout << "Shrubbery: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery: Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Shrubbery: Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Shrubbery: Assignment operator called" << std::endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery: Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    try {
        if (!getIsSigned())
            throw AForm::FormNotSignedException();

        if (executor.getGrade() > this->getExecute())
            throw AForm::GradeTooLowTooExecute();

        std::ofstream file((_target + "_shrubbery").c_str());

        if (!file.is_open())
            throw AForm::FileNotOpenedException();

        file << "    /\\\n";
        file << "   /**\\\n";
        file << "  /****\\\n";
        file << " /******\\\n";
        file << "/********\\\n";
        file << "    ||\n";
        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw (AForm::GradeTooLowTooExecute());
    }
};

std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    std::cout << "ShrubberyCreationForm : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
    return (out);
};