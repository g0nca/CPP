#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n----- Basic Array Test -----\n" << std::endl;
    
    // Create array of Animals as required by the subject
    Animal* animals[10];
    
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
    
    std::cout << "\n----- Delete Animals -----\n" << std::endl;
    
    // Delete all allocated animals
    for (int i = 0; i < 10; i++) {
        std::cout << "Deleting animal " << i << std::endl;
        delete animals[i];
    }
    
    return 0;
}