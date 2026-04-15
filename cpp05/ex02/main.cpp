#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void printHeader(const std::string& title)
{
	std::cout << "\n";
	std::cout << "===================================================" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
	std::cout << "===================================================" << std::endl;
}
 
 
int main()
{
	std::cout << "TESTING BUREAUCRAT AND FORM CLASSES" << std::endl;
	{
		printHeader("ShrubberyCreationForm");
		Bureaucrat Bureaucrat("Joao", 20);
		RobotomyRequestForm RobotomyForm("Primeiro");
	
		Bureaucrat.signForm(RobotomyForm);
		RobotomyForm.execute(Bureaucrat);
	}
	return 0;
}