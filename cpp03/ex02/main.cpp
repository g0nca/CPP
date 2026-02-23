#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    // ClapTrap Tests (from ex00)
    std::cout << std::endl << std::endl;
    std::cout << "ClapTrap Test" << std::endl;
    {
        ClapTrap claptrap("Kim");

        claptrap.attack("Handsome Jack");
        claptrap.takeDamage(5);
        claptrap.beRepaired(3);
        claptrap.displayInfo();
    }

    // ScavTrap Test (from ex01)
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Basic Test" << std::endl;
    {
        ScavTrap scavtrap("Guardian");
        scavtrap.displayInfo();
        scavtrap.attack("Hyperion Robot");
        scavtrap.takeDamage(20);
        scavtrap.beRepaired(15);
        scavtrap.guardGate();
        scavtrap.displayInfo();
    }
    
    // FragTrap Tests (new for ex02)
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "FragTrap Basic Test" << std::endl;
    {
        FragTrap fragtrap("Destroyer");
        fragtrap.displayInfo();
        fragtrap.attack("Badass Enemy");
        fragtrap.takeDamage(30);
        fragtrap.beRepaired(20);
        fragtrap.highFivesGuys();
        fragtrap.displayInfo();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "FragTrap Energy Test" << std::endl;
    {
        FragTrap fragtrap("Bombshell");
        fragtrap.displayInfo();
        
        // Test multiple attacks to deplete energy points
        for (int i = 0; i < 6; i++) {
            std::cout << "Attack " << i+1 << ":" << std::endl;
            fragtrap.attack("Enemy Bot");
            fragtrap.displayInfo();
        }
        
        // Try to repair after attacks
        fragtrap.beRepaired(15);
        fragtrap.displayInfo();
        
        // Try high fives with low energy
        fragtrap.highFivesGuys();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "FragTrap Damage Test" << std::endl;
    {
        FragTrap fragtrap("Annihilator");
        fragtrap.displayInfo();
        
        // Test high damage
        fragtrap.takeDamage(70);
        fragtrap.displayInfo();
        
        // Try actions after high damage
        fragtrap.attack("Enemy");
        fragtrap.beRepaired(30);
        fragtrap.highFivesGuys();
        
        // Final blow
        fragtrap.takeDamage(60);
        fragtrap.displayInfo();
        
        // Try actions after destruction
        fragtrap.attack("Enemy");
        fragtrap.beRepaired(100);
        fragtrap.highFivesGuys();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "FragTrap Copy Constructor Test" << std::endl;
    {
        FragTrap original("Original");
        original.displayInfo();
        
        // Make some changes
        original.attack("Enemy");
        original.takeDamage(40);
        std::cout << "Original after changes:" << std::endl;
        original.displayInfo();
        
        // Use copy constructor
        FragTrap copy(original);
        std::cout << "Copy status:" << std::endl;
        copy.displayInfo();
        
        // Modify only the original
        original.takeDamage(25);
        original.beRepaired(15);
        
        std::cout << "After modifying only the original:" << std::endl;
        std::cout << "Original: ";
        original.displayInfo();
        std::cout << "Copy: ";
        copy.displayInfo();
        
        // Test specific FragTrap function on both
        original.highFivesGuys();
        copy.highFivesGuys();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "FragTrap Assignment Operator Test" << std::endl;
    {
        FragTrap first("First");
        FragTrap second("Second");
        
        // Modify the first FragTrap
        first.attack("Enemy");
        first.takeDamage(35);
        first.beRepaired(20);
        first.highFivesGuys();
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "First: ";
        first.displayInfo();
        std::cout << "Second: ";
        second.displayInfo();
        
        // Use assignment operator
        second = first;
        
        std::cout << "After assignment (second = first):" << std::endl;
        std::cout << "First: ";
        first.displayInfo();
        std::cout << "Second: ";
        second.displayInfo();
        
        // Modify only the first
        first.beRepaired(15);
        first.attack("Another enemy");
        
        std::cout << "After modifying only the first:" << std::endl;
        std::cout << "First: ";
        first.displayInfo();
        std::cout << "Second: ";
        second.displayInfo();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Class Hierarchy Demonstration Test" << std::endl;
    {
        std::cout << "Creating a ClapTrap:" << std::endl;
        ClapTrap claptrap("Basic");
        claptrap.displayInfo();
        
        std::cout << "\nCreating a ScavTrap:" << std::endl;
        ScavTrap scavtrap("Guardian");
        scavtrap.displayInfo();
        
        std::cout << "\nCreating a FragTrap:" << std::endl;
        FragTrap fragtrap("Destroyer");
        fragtrap.displayInfo();
        
        // Show that all can perform base class actions
        std::cout << "\nAll can attack:" << std::endl;
        claptrap.attack("Target1");
        scavtrap.attack("Target2");
        fragtrap.attack("Target3");
        
        // Show unique abilities
        std::cout << "\nUnique abilities:" << std::endl;
        scavtrap.guardGate();
        fragtrap.highFivesGuys();
    }

    return 0;
}