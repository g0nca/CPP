#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _formName("Default Form"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150) {
    std::cout << "Form : Default Constructor " << std::endl;
};

Form::Form(std::string form_name, int gradeSign, int gradeExecute): _formName(form_name), _isSigned(false), _gradeTosign(gradeSign), _gradeToexecute(gradeExecute) {
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form : Name Constructor " << std::endl;
};


Form::Form(const Form &copy) : _formName(copy._formName), _gradeTosign(copy._gradeTosign), _gradeToexecute(copy._gradeToexecute) {
    std::cout << "Form : Copy Constructor " << std::endl;
};


Form    &Form::operator=(const Form &copy){

    if (this != &copy)
    {
        this->_isSigned = copy._isSigned;
        std::cout << "Form : Assignment Operator " << std::endl;
    }
    return (*this);
};

Form::~Form(){
    std::cout << "Form : Destructor " << std::endl;
};


// Getters
std::string     Form::getName() const {
    return (this->_formName);
};

bool            Form::getIsSigned() const {
    return (this->_isSigned);
};

int             Form::getSign() const {
    return (this->_gradeTosign);
};

int             Form::getExecute() const {
    return (this->_gradeToexecute);
};

void            Form::beSigned(Bureaucrat &bureaucrat) {

    std::cout << "Grade Bureacrat " << bureaucrat.getGrade() << std::endl;
    std::cout << "Grade To Sign " << this->_gradeTosign << std::endl; 
    if (bureaucrat.getGrade() > this->_gradeTosign)
        throw (Form::GradeTooLowException());
    _isSigned = true;
};

std::ostream &operator<<(std::ostream &out, Form &form)
{
    std::cout << "Form name: " << form.getName() << std::endl;
    std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    std::cout << "Grade to sign: " << form.getSign() << std::endl;
    std::cout << "Grade to execute: " << form.getExecute() << std::endl;
    return out;
}
