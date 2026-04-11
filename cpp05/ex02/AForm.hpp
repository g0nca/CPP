#pragma once

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class AForm 
{
    protected:
        const std::string       _formName;
        bool                    _isSigned;
        const int               _gradeTosign;
        const int               _gradeToexecute;
    public:
        AForm(void);
        AForm(std::string form_name, int gradeSign, int gradeExecute);
        AForm(const AForm &copy);
        virtual ~AForm();

        AForm &operator=(const AForm &copy);

        std::string     getName() const;
        bool            getIsSigned() const;
        int             getSign() const;
        int             getExecute() const;

        virtual void            beSigned(Bureaucrat &bureaucrat) = 0;
        void                    beExecuted(Bureaucrat &bureaucrat);

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

        class FileNotOpenedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};
std::ostream &operator<<(std::ostream &out, AForm &form);
