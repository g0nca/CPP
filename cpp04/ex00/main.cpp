#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n----- Basic Tests (from subject) -----\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the animal sound!
    
    std::cout << "\n----- Destructors -----\n" << std::endl;
    
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n----- Test with regular objects (not pointers) -----\n" << std::endl;
    
    Animal animal;
    Dog dog;
    Cat cat;
    
    std::cout << "Animal type: " << animal.getType() << std::endl;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Cat type: " << cat.getType() << std::endl;
    
    std::cout << "Animal sound: ";
    animal.makeSound();
    std::cout << "Dog sound: ";
    dog.makeSound();
    std::cout << "Cat sound: ";
    cat.makeSound();
    
    std::cout << "\n----- Test with WrongAnimal and WrongCat -----\n" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "WrongAnimal sound: ";
    wrongAnimal->makeSound();
    std::cout << "WrongCat sound (through WrongAnimal pointer): ";
    wrongCat->makeSound(); // Should output WrongAnimal sound (not polymorphic)
    
    const WrongCat* actualWrongCat = new WrongCat();
    std::cout << "WrongCat sound (through WrongCat pointer): ";
    actualWrongCat->makeSound(); // Should output WrongCat sound
    
    std::cout << "\n----- Test copycat -----\n" << std::endl;
    
    Cat originalCat;
    std::cout << "Original cat type: " << originalCat.getType() << std::endl;
    std::cout << "Original cat sound: ";
    originalCat.makeSound();
    
    Cat copyCat(originalCat);
    std::cout << "Copy cat type: " << copyCat.getType() << std::endl;
    std::cout << "Copy cat sound: ";
    copyCat.makeSound();
    
    std::cout << "\n----- Destructors for Wrong classes -----\n" << std::endl;
    
    delete wrongAnimal;
    delete wrongCat;
    delete actualWrongCat;

    return 0;
}