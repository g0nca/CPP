#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _formName("Default Form"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150) {
    std::cout << "Form : Default Constructor " << std::endl;
};

AForm::AForm(std::string form_name, int gradeSign, int gradeExecute): _formName(form_name), _isSigned(false), _gradeTosign(gradeSign), _gradeToexecute(gradeExecute) {
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form : Name Constructor " << std::endl;
};


AForm::AForm(const Form &copy) : _formName(copy._formName), _gradeTosign(copy._gradeTosign), _gradeToexecute(copy._gradeToexecute) {
    std::cout << "Form : Copy Constructor " << std::endl;
};


AForm    &AForm::operator=(const AForm &copy){

    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
        std::cout << "Form : Assignment Operator " << std::endl;
    }
    return (*this);
};

AForm::~AForm(){
    std::cout << "Form : Destructor " << std::endl;
};


// Getters
std::string     AForm::getName() const {
    return (this->_formName);
};

bool            AForm::getIsSigned() const {
    return (this->_isSigned);
};

int             AForm::getSign() const {
    return (this->_gradeTosign);
};

int             AForm::getExecute() const {
    return (this->_gradeToexecute);
};

void            AForm::beSigned(Bureaucrat &bureaucrat) {

    std::cout << "Grade Bureacrat " << bureaucrat.getGrade() << std::endl;
    std::cout << "Grade To Sign " << this->_gradeTosign << std::endl; 
    if (bureaucrat.getGrade() > this->_gradeTosign)
        throw (Form::GradeTooLowException());
    _isSigned = true;
};

void AForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
};

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not Signed !");
}

const char* AForm::FileNotOpenedException::what() const throw()
{
    return ("Could not Open File");
}

std::ostream &operator<<(std::ostream &out, AForm &form)
{
    std::cout << "Form name: " << form.getName() << std::endl;
    std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    std::cout << "Grade to sign: " << form.getSign() << std::endl;
    std::cout << "Grade to execute: " << form.getExecute() << std::endl;
    return (out);
};

