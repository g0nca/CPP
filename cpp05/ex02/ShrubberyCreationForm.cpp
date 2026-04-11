#include "ShrubberyCreationForm.hpp"

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
    AForm::beExecuted(executor); // Usa beExecuted em vez de execute
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        throw AForm::FileNotOpenedException();
    }
    std::ofstream file(target + "_shrubbery");
    file << "    /\\\n";
    file << "   /**\\\n";
    file << "  /****\\\n";
    file << " /******\\\n";
    file << "/********\\\n";
    file << "    ||\n";
    file.close();
};

std::ostream    &operator<<(std::ostream &out, ShrubberyCreationForm &form)
{
    out << "ShrubberyCreationForm : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.isSigned() << std::endl;
    return (out);
};