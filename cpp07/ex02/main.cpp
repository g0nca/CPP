#include "Array.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void displayTestResult(const std::string& testName, bool success) {
    std::cout << (success ? GREEN : RED) << "[" << (success ? "OK" : "KO") << "]" << RESET;
    std::cout << " " << testName << std::endl;
}

int main() {
    std::cout << "===== Testing Array Template Class =====" << std::endl;
    
    // Test empty constructor
    {
        std::cout << "\n1. Testing empty constructor:" << std::endl;
        Array<int> emptyArray;
        displayTestResult("Empty array has size 0", emptyArray.size() == 0);
        
        try {
            // This should throw an exception
            emptyArray[0] = 42;
            displayTestResult("Accessing element in empty array", false);
        } catch (const std::exception& e) {
            displayTestResult("Exception thrown when accessing element in empty array", true);
        }
    }
    
    // Test constructor with size parameter
    {
        std::cout << "\n2. Testing constructor with size parameter:" << std::endl;
        const unsigned int size = 5;
        Array<int> intArray(size);
        
        displayTestResult("Array has correct size", intArray.size() == size);
        
        // Test element modification
        intArray[2] = 42;
        displayTestResult("Element can be modified", intArray[2] == 42);
        
        // Test out-of-bounds access
        try {
            intArray[size] = 100;
            displayTestResult("Out-of-bounds access detection", false);
        } catch (const std::exception& e) {
            displayTestResult("Exception thrown for out-of-bounds access", true);
        }
    }
    
    // Test copy constructor
    {
        std::cout << "\n3. Testing copy constructor:" << std::endl;
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        Array<int> copy(original);
        
        displayTestResult("Copy has same size as original", copy.size() == original.size());
        displayTestResult("Copy has same elements as original", 
                        copy[0] == original[0] && 
                        copy[1] == original[1] && 
                        copy[2] == original[2]);
        
        // Modify original and check that copy is unchanged
        original[1] = 99;
        displayTestResult("Modifying original doesn't affect copy", copy[1] == 20);
        
        // Modify copy and check that original is unchanged
        copy[2] = 88;
        displayTestResult("Modifying copy doesn't affect original", original[2] == 30);
    }
    
    // Test assignment operator
    {
        std::cout << "\n4. Testing assignment operator:" << std::endl;
        Array<int> first(4);
        first[0] = 1;
        first[1] = 2;
        first[2] = 3;
        first[3] = 4;
        
        Array<int> second(2);
        second[0] = 10;
        second[1] = 20;
        
        // Assign first to second
        second = first;
        
        displayTestResult("After assignment, second has same size as first", 
                        second.size() == first.size());
        displayTestResult("After assignment, second has same elements as first", 
                        second[0] == first[0] && 
                        second[1] == first[1] && 
                        second[2] == first[2] && 
                        second[3] == first[3]);
        
        // Modify first and check that second is unchanged
        first[0] = 100;
        displayTestResult("Modifying first doesn't affect second after assignment", second[0] == 1);
        
        // Modify second and check that first is unchanged
        second[1] = 200;
        displayTestResult("Modifying second doesn't affect first after assignment", first[1] == 2);
        
    }
    
    // Test with a different type
    {
        std::cout << "\n5. Testing with string type:" << std::endl;
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";
        
        displayTestResult("String array stores correct values", 
                        strArray[0] == "Hello" && 
                        strArray[1] == "World" && 
                        strArray[2] == "!");
        
        Array<std::string> copyStr(strArray);
        displayTestResult("Copy constructor works with strings", 
                        copyStr[0] == "Hello" && 
                        copyStr[1] == "World" && 
                        copyStr[2] == "!");
    }
    
    // Test with pointers
    {
        std::cout << "\n6. Special test with pointers (mentioned in the exercise):" << std::endl;
        try {
            int * a = new int();
            std::cout << "Value at *a: " << *a << std::endl;
            delete a;
            displayTestResult("Pointer test successful", true);
        } catch (const std::exception& e) {
            displayTestResult("Pointer test failed", false);
        }
    }
    
    std::cout << "\nAll tests completed." << std::endl;
    
    return 0;
}