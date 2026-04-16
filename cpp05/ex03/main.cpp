#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n";
    std::cout << "===================================================" << std::endl;
    std::cout << "=== " << title << " ===" << std::endl;
    std::cout << "===================================================" << std::endl;
}

void testInternBasic() {
    printHeader("TEST INTERN BASIC FUNCTIONALITY");
    
    Intern someRandomIntern;
    AForm *rrf = NULL;
    AForm *random = NULL;
    
    std::cout << "Creating a robotomy request form..." << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
    }
    
    std::cout << "\nTrying to create an invalid form type..." << std::endl;
    try {
        random = someRandomIntern.makeForm("random", "Bender");
        if (random) {
            std::cout << *random << std::endl;
        }
    } catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting form with bureaucrats..." << std::endl;
    Bureaucrat lowLevel("LowLevel", 150);
    std::cout << lowLevel << std::endl;
    
    if (rrf) {
        lowLevel.signForm(*rrf);
        
        Bureaucrat midLevel("MidLevel", 40);
        std::cout << midLevel << std::endl;
        
        midLevel.signForm(*rrf);
        midLevel.execute(*rrf);
        
        delete rrf;
    }
}

void testInternAllForms() {
    printHeader("TEST INTERN ALL FORM TYPES");
    
    Intern someRandomIntern;
    AForm *rrf = NULL;
    AForm *scf = NULL;
    AForm *ppf = NULL;
    
    std::cout << "Creating all types of forms..." << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    
    if (rrf && scf && ppf) {
        std::cout << "\nForms created:" << std::endl;
        std::cout << *rrf << std::endl;
        std::cout << *scf << std::endl;
        std::cout << *ppf << std::endl;
        
        std::cout << "\nTesting with bureaucrats..." << std::endl;
        Bureaucrat lowLevel("LowLevel", 150);
        std::cout << lowLevel << std::endl;
        
        lowLevel.signForm(*rrf);
        lowLevel.signForm(*scf);
        lowLevel.signForm(*ppf);
        
        Bureaucrat highLevel("HighLevel", 5);
        std::cout << highLevel << std::endl;
        
        highLevel.signForm(*rrf);
        highLevel.signForm(*scf);
        highLevel.signForm(*ppf);
        
        highLevel.execute(*rrf);
        highLevel.execute(*scf);
        highLevel.execute(*ppf);
        
        delete rrf;
        delete scf;
        delete ppf;
    }
}


int main() {
    // Test basic intern functionality
    testInternBasic();
    
    // Test intern with all form types
    testInternAllForms();
    
    return 0;
}