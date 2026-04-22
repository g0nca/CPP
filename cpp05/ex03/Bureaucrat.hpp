#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const   std::string     _name;
        int                     _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &copy);

        std::string     getName() const;
        int             getGrade() const;

        void            incrementBureaucrat();
        void            decrementBureaucrat();

        void            signForm(AForm &form);
        void            execute(AForm const &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too High");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Grade is too Low");
                }
        };

        class FormAlreadySigned : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("form already signed");
                }
        };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);