#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printHeader(const std::string& title)
{
    std::cout << "\n";
    std::cout << "===================================================" << std::endl;
    std::cout << "=== " << title << " ===" << std::endl;
    std::cout << "===================================================" << std::endl;
}

void testShrubberyCreationForm()
{
    printHeader("SHRUBBERY CREATION FORM TEST");
    
    // Bureaucrat de baixo nível (pode assinar, não pode executar)
    Bureaucrat lowBureaucrat("LowLevel", 140);
    std::cout << lowBureaucrat << std::endl;
    
    // Bureaucrat de alto nível (pode assinar e executar)
    Bureaucrat highBureaucrat("HighLevel", 1);
    std::cout << highBureaucrat << std::endl;
    
    // Teste com formulário
    ShrubberyCreationForm form("Garden");
    std::cout << "Form: " << form << std::endl;
    
    // Teste de assinatura e execução com bureaucrat de baixo nível
    std::cout << "\n--- Testing with Low Level Bureaucrat ---" << std::endl;
    lowBureaucrat.signForm(form);
    lowBureaucrat.execute(form);
    
    // Teste de execução com bureaucrat de alto nível em formulário já assinado
    std::cout << "\n--- Testing with High Level Bureaucrat ---" << std::endl;
    highBureaucrat.execute(form);
}

void testRobotomyRequestForm()
{
    printHeader("ROBOTOMY REQUEST FORM TEST");
    
    // Bureaucrat de médio nível (pode assinar, não pode executar)
    Bureaucrat midBureaucrat("MidLevel", 70);
    std::cout << midBureaucrat << std::endl;
    
    // Bureaucrat de alto nível (pode assinar e executar)
    Bureaucrat highBureaucrat("HighLevel", 1);
    std::cout << highBureaucrat << std::endl;
    
    // Teste com formulário
    RobotomyRequestForm form("Robot");
    std::cout << "Form: " << form << std::endl;
    
    // Teste de assinatura e execução com bureaucrat de médio nível
    std::cout << "\n--- Testing with Mid Level Bureaucrat ---" << std::endl;
    midBureaucrat.signForm(form);
    midBureaucrat.execute(form);
    
    // Teste de execução com bureaucrat de alto nível em formulário já assinado
    std::cout << "\n--- Testing with High Level Bureaucrat (Multiple Attempts) ---" << std::endl;
    for (int i = 0; i < 3; i++)
	{
        std::cout << "Attempt " << i + 1 << ": ";
        highBureaucrat.execute(form);
    }
}

void testPresidentialPardonForm()
{
    printHeader("PRESIDENTIAL PARDON FORM TEST");
    
    // Bureaucrat de alto nível (pode assinar e executar)
    Bureaucrat highBureaucrat("HighLevel", 1);
    std::cout << highBureaucrat << std::endl;
    
    // Bureaucrat de médio nível (pode assinar, não pode executar)
    Bureaucrat midBureaucrat("MidLevel", 15);
    std::cout << midBureaucrat << std::endl;
    
    // Teste com formulário
    PresidentialPardonForm form("Criminal");
    std::cout << "Form: " << form << std::endl;
    
    // Teste de assinatura com bureaucrat de médio nível
    std::cout << "\n--- Testing with Mid Level Bureaucrat ---" << std::endl;
    midBureaucrat.signForm(form);
    midBureaucrat.execute(form);
    
    // Teste de execução com bureaucrat de alto nível em formulário já assinado
    std::cout << "\n--- Testing with High Level Bureaucrat ---" << std::endl;
    highBureaucrat.signForm(form);
    highBureaucrat.execute(form);
}

void testEdgeCases()
{
    printHeader("EDGE CASES TEST");
    
    // Teste de execução de formulário não assinado
    std::cout << "\n--- Testing Unsigned Form Execution ---" << std::endl;
    Bureaucrat chief("Chief", 1);
    ShrubberyCreationForm form("UnsignedForm");
    
    std::cout << "Form state: " << form << std::endl;
    std::cout << "Trying to execute unsigned form:" << std::endl;
    chief.execute(form);
    
    // Teste de tentar assinar um formulário já assinado
    std::cout << "\n--- Testing Already Signed Form ---" << std::endl;
    chief.signForm(form);
    std::cout << "Form after signing: " << form << std::endl;
    
    std::cout << "Trying to sign already signed form:" << std::endl;
    chief.signForm(form);
}

int main()
{
    std::cout << "TESTING BUREAUCRAT FORMS" << std::endl;
    
    // Testes para cada tipo de formulário
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    
    // Testes de casos especiais
    testEdgeCases();
    
    return 0;
}