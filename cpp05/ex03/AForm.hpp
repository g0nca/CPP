#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

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

        void            beSigned(Bureaucrat &bureaucrat);
        //void            beExecuted(Bureaucrat const &bureaucrat) const;
        virtual void    execute(Bureaucrat const &bureaucrat) const = 0;

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

        class FormCreationException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Form creation failed");
                }
        };

        class FileNotOpenedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("Could not open file");
                }
        };
        
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("Form is not signed");
                }
        };

};
std::ostream &operator<<(std::ostream &out, AForm &form);
