#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

int main()
{
    std::cout << std::endl << "----- Basic Array Test -----\n" << std::endl;
    
    // Create array of AAnimals as required by the subject
    AAnimal* animals[10];
    
    // Fill half with Dogs and half with Cats
    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            std::cout << "Creating Dog " << i << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "Creating Cat " << i << std::endl;
            animals[i] = new Cat();
        }
    }
    
    std::cout << "\n----- Test Sounds -----\n" << std::endl;
    
    // Make them all sound
    for (int i = 0; i < 10; i++) {
        std::cout << "Animal " << i << " (type: " << animals[i]->getType() << ") says: ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n----- Deep Copy Test -----\n" << std::endl;
    
    // Test deep copy with Dog
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I want to play fetch!");
    
    // Create a copy using copy constructor
    Dog copyDog(originalDog);
    
    // Show that they have the same idea initially
    std::cout << "Original Dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    // Modify the original to prove deep copy
    originalDog.getBrain()->setIdea(0, "I changed my mind!");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "Original Dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    // Test deep copy with Cat
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I want to sleep all day!");
    
    // Create a copy using assignment operator
    Cat copyCat = originalCat;
    
    // Show that they have the same idea initially
    std::cout << std::endl << "Original Cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat idea: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    // Modify the original to prove deep copy
    originalCat.getBrain()->setIdea(0, "I want to catch mice now!");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "Original Cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat idea: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    std::cout  << std::endl << "----- WrongAnimal Polymorphism Test -----\n" << std::endl;
    
    // Demonstrating the difference between correct and wrong implementation
    AAnimal* animal = new Cat();
    WrongAnimal* wrongAnimal = new WrongCat();
    
    std::cout << "Correct implementation:" << std::endl;
    std::cout << "animal->getType(): " << animal->getType() << std::endl;
    std::cout << "animal->makeSound(): ";
    animal->makeSound();  // This will call Cat::makeSound() due to virtual function
    
    std::cout << std::endl << "Wrong implementation:" << std::endl;
    std::cout << "wrongAnimal->getType(): " << wrongAnimal->getType() << std::endl;
    std::cout << "wrongAnimal->makeSound(): ";
    wrongAnimal->makeSound();  // This will call WrongAnimal::makeSound() because it's not virtual
    
    // Also demonstrate with direct objects
    std::cout << std::endl << "Direct objects:" << std::endl;
    WrongCat wrongCat;
    std::cout << "wrongCat.getType(): " << wrongCat.getType() << std::endl;
    std::cout << "wrongCat.makeSound(): ";
    wrongCat.makeSound();  // This will call WrongCat::makeSound() as expected
    
    // Clean up the test objects
    delete animal;
    delete wrongAnimal;
    
    std::cout << "\n----- Delete Animals -----\n" << std::endl;
    
    // Delete all allocated animals
    for (int i = 0; i < 10; i++) {
        std::cout << "Deleting animal " << i << std::endl;
        delete animals[i];
    }
    
    return 0;
}