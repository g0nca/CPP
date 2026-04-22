#include "Bureaucrat.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n";
    std::cout << "===================================================" << std::endl;
    std::cout << "=== " << title << " ===" << std::endl;
    std::cout << "===================================================" << std::endl;
}

void testConstructor()
{
    printHeader("CONSTRUCTOR TESTS");
    
    std::cout << "Testing valid constructor:" << std::endl;
    try
	{
        Bureaucrat normal("Normal", 75);
        std::cout << normal << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting too high grade (0):" << std::endl;
    try
	{
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting too low grade (151):" << std::endl;
    try
	{
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testIncrementDecrement()
{
    printHeader("INCREMENT/DECREMENT TESTS");
    
    std::cout << "Testing normal increment/decrement:" << std::endl;
    try
	{
        Bureaucrat normal("Normal", 75);
        std::cout << "Initial: " << normal << std::endl;
        
        normal.incrementBureaucrat();
        std::cout << "After increment: " << normal << std::endl;
        
        normal.decrementBureaucrat();
        std::cout << "After decrement: " << normal << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting increment at highest grade (1):" << std::endl;
    try
	{
        Bureaucrat highest("Highest", 1);
        std::cout << "Initial: " << highest << std::endl;
        
        highest.incrementBureaucrat();
        std::cout << "After increment: " << highest << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting decrement at lowest grade (150):" << std::endl;
    try
	{
        Bureaucrat lowest("Lowest", 150);
        std::cout << "Initial: " << lowest << std::endl;
        
        lowest.decrementBureaucrat();
        std::cout << "After decrement: " << lowest << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testGetters()
{
    printHeader("GETTER TESTS");
    
    Bureaucrat bureaucrat("TestBureaucrat", 42);
    
    std::cout << "Full info: " << bureaucrat << std::endl;
    std::cout << "Name: " << bureaucrat.getName() << std::endl;
    std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
}

void testMultipleChanges()
{
    printHeader("MULTIPLE CHANGES TEST");
    try
	{
        Bureaucrat b("RiseFall", 75);
        std::cout << "Initial: " << b << std::endl;
        
        std::cout << "\nPromoting 10 times:" << std::endl;
        for (int i = 0; i < 10; i++)
		{
            b.incrementBureaucrat();
            std::cout << "After promotion " << i + 1 << ": " << b << std::endl;
        }
        
        std::cout << "\nDemoting 15 times:" << std::endl;
        for (int i = 0; i < 15; i++)
		{
            b.decrementBureaucrat();
            std::cout << "After demotion " << i + 1 << ": " << b << std::endl;
        }
        
        // This should cause an exception (would reach 151 if allowed)
        std::cout << "\nTrying to demote too far:" << std::endl;
        for (int i = b.getGrade(); i < 152; i++)
		{
            b.decrementBureaucrat();
            std::cout << "Current grade: " << b.getGrade() << std::endl;
        }
    }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "TESTING BUREAUCRAT CLASS" << std::endl;
    
    // Test constructors with various grades
    testConstructor();
    
    // Test increment and decrement functions
    testIncrementDecrement();
    
    // Test getters
    testGetters();
    
    // Test multiple promotions and demotions
    testMultipleChanges();
    
    return 0;
}