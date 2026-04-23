#include "Bureaucrat.hpp"
#include "Form.hpp"

void printHeader(const std::string& title)
{
	std::cout << "\n";
	std::cout << "===================================================" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
	std::cout << "===================================================" << std::endl;
}
 
void testFormCreation()
{
	printHeader("FORM CREATION TEST");
 
	// Teste de criação de formulários com grades válidos
	std::cout << "Creating forms with valid grades:" << std::endl;
	try
	{
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
		
		Form form2("Permission Form", 1, 1);
		std::cout << form2 << std::endl;
		
		Form form3("Standard Form", 150, 150);
		std::cout << form3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	 
	// Teste de criação de formulários com grades inválidos
	std::cout << "\nAttempting to create forms with invalid grades:" << std::endl;
	 
	try
	{
		std::cout << "Creating form with sign grade 0 (too high):" << std::endl;
		Form invalidForm1("Invalid Form", 0, 50);
		std::cout << invalidForm1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	 
	try
	{
		std::cout << "Creating form with execute grade 151 (too low):" << std::endl;
		Form invalidForm2("Invalid Form", 50, 151);
		std::cout << invalidForm2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
 
void testFormSigning()
{
	printHeader("FORM SIGNING TEST");
	try
	{
		// Criação de burocratas com diferentes níveis
		Bureaucrat bureaucrat_highLevel("Director", 444);
		Bureaucrat bureaucrat_midLevel("Manager", 75);
		Bureaucrat bureaucrat_lowLevel("Intern", 150);
		
		std::cout << "Bureaucrats created:" << std::endl;
		std::cout << bureaucrat_highLevel << std::endl;
		std::cout << bureaucrat_midLevel << std::endl;
		std::cout << bureaucrat_lowLevel << std::endl;
		
		// Criação de formulários com diferentes requisitos
		Form easyForm("Easy Form", 150, 150);
		Form mediumForm("Medium Form", 75, 75);
		Form hardForm("Hard Form", 1, 1);
		
		std::cout << "\nForms created:" << std::endl;
		std::cout << easyForm << std::endl;
		std::cout << mediumForm << std::endl;
		std::cout << hardForm << std::endl;
		
		// Teste de assinatura: baixo nível tentando assinar formas de diferentes dificuldades
		std::cout << "\n--- Low level bureaucrat signing attempts ---" << std::endl;
		bureaucrat_lowLevel.signForm(easyForm);  // Deve conseguir assinar
		bureaucrat_lowLevel.signForm(mediumForm); // Não deve conseguir assinar
		bureaucrat_lowLevel.signForm(hardForm);   // Não deve conseguir assinar
		
		// Teste de assinatura: nível médio tentando assinar
		std::cout << "\n--- Medium level bureaucrat signing attempts ---" << std::endl;
		bureaucrat_midLevel.signForm(easyForm);  // Já está assinado
		bureaucrat_midLevel.signForm(mediumForm); // Deve conseguir assinar
		bureaucrat_midLevel.signForm(hardForm);   // Não deve conseguir assinar
		
		// Teste de assinatura: alto nível tentando assinar
		std::cout << "\n--- High level bureaucrat signing attempts ---" << std::endl;
		bureaucrat_highLevel.signForm(easyForm);  // Já está assinado
		bureaucrat_highLevel.signForm(mediumForm); // Já está assinado
		bureaucrat_highLevel.signForm(hardForm);   // Deve conseguir assinar
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
 
void testFormGetters()
{
	printHeader("FORM GETTERS TEST");
	 
	Form form("Confidential Form", 20, 10);
	 
	std::cout << "Form details:" << std::endl;
	std::cout << "Name: " << form.getName() << std::endl;
	std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	std::cout << "Grade required to sign: " << form.getSign() << std::endl;
	std::cout << "Grade required to execute: " << form.getExecute() << std::endl;
	 
	// Assinar o formulário e testar novamente
	Bureaucrat boss("Boss", 1);
	boss.signForm(form);
	 
	std::cout << "\nAfter signing:" << std::endl;
	std::cout << "Name: " << form.getName() << std::endl;
	std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	std::cout << "Grade required to sign: " << form.getSign() << std::endl;
	std::cout << "Grade required to execute: " << form.getExecute() << std::endl;
}
 
void testAlreadySigned()
{
	printHeader("ALREADY SIGNED FORM TEST");
	 
	Form form("Contract", 50, 25);
	Bureaucrat bureaucrat("Department Head", 30);
	 
	std::cout << "Form initial state: " << form << std::endl;
	std::cout << "Bureaucrat: " << bureaucrat << std::endl;
	 
	// Primeira tentativa de assinatura
	std::cout << "\nFirst attempt to sign:" << std::endl;
	bureaucrat.signForm(form);
	 
	// Segunda tentativa de assinatura
	std::cout << "\nSecond attempt to sign (already signed):" << std::endl;
	bureaucrat.signForm(form);
}
 
void testBureaucratGradeBoundaries()
{
	printHeader("BUREAUCRAT GRADE BOUNDARIES TEST");
	 
	try
	{
		std::cout << "Creating bureaucrat with highest possible grade (1):" << std::endl;
		Bureaucrat topBureaucrat("Top", 1);
		std::cout << topBureaucrat << std::endl;
		 
		std::cout << "\nTrying to promote beyond highest grade:" << std::endl;
		topBureaucrat.incrementBureaucrat(); // Should throw exception
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nCreating bureaucrat with lowest possible grade (150):" << std::endl;
		Bureaucrat bottomBureaucrat("Bottom", 150);
		std::cout << bottomBureaucrat << std::endl;
		 
		std::cout << "\nTrying to demote beyond lowest grade:" << std::endl;
		bottomBureaucrat.decrementBureaucrat(); // Should throw exception
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
 
int main()
{
	std::cout << "TESTING BUREAUCRAT AND FORM CLASSES" << std::endl;
	 
	// Teste de criação de formulário e validação de grades
	testFormCreation();
	 
	// Teste de assinatura de formulários
	testFormSigning();
	 
	// Teste dos getters do formulário
	testFormGetters();
	 
	// Teste de tentar assinar um formulário já assinado
	testAlreadySigned();
	 
	// Teste dos limites de grade do burocrata
	testBureaucratGradeBoundaries();
	 
	return 0;
}