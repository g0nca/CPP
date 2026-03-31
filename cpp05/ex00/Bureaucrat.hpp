#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const   std::string _name;
        int     _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &copy);

    //getter & setter
        std::string     getName() const;
        int             getGrade() const;

        void            incrementBureaucrat();
        void            decrementBureaucrat();

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

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);