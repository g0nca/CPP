#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form 
{
    private:
        const std::string       _formName;
        bool                    _isSigned;
        const int               _gradeTosign;
        const int               _gradeToexecute;
    public:
        Form(void);
        Form(std::string form_name, int gradeSign, int gradeExecute);
        Form(const Form &copy);
        ~Form();

        Form &operator=(const Form &copy);

        std::string     getName() const;
        bool            getIsSigned() const;
        int             getSign() const;
        int             getExecute() const;

        void            beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };

};
std::ostream &operator<<(std::ostream &out, Form &form);
