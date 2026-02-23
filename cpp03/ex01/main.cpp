#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

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
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Second ClapTrap Test" << std::endl;
    {
        ClapTrap claptrap("Pam");
        claptrap.displayInfo();
        claptrap.attack("Handsome Jack");
        claptrap.takeDamage(9);
        claptrap.beRepaired(9);
        claptrap.displayInfo();
    }

    // ScavTrap Tests (new for ex01)
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
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Energy Test" << std::endl;
    {
        ScavTrap scavtrap("Sentinel");
        scavtrap.displayInfo();
        
        // Test multiple attacks to deplete energy points
        for (int i = 0; i < 5; i++) {
            std::cout << "Attack " << i+1 << ":" << std::endl;
            scavtrap.attack("Enemy Bot");
            scavtrap.displayInfo();
        }
        
        // Try to repair after attacks
        scavtrap.beRepaired(10);
        scavtrap.displayInfo();
        
        // Try guardGate with low energy
        scavtrap.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Damage Test" << std::endl;
    {
        ScavTrap scavtrap("Protector");
        scavtrap.displayInfo();
        
        // Test high damage
        scavtrap.takeDamage(80);
        scavtrap.displayInfo();
        
        // Try actions after high damage
        scavtrap.attack("Enemy");
        scavtrap.beRepaired(30);
        scavtrap.guardGate();
        
        // Final blow
        scavtrap.takeDamage(50);
        scavtrap.displayInfo();
        
        // Try actions after destruction
        scavtrap.attack("Enemy");
        scavtrap.beRepaired(100);
        scavtrap.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Copy Constructor Test" << std::endl;
    {
        ScavTrap original("Original");
        original.displayInfo();
        
        // Make some changes
        original.attack("Enemy");
        original.takeDamage(30);
        std::cout << "Original after changes:" << std::endl;
        original.displayInfo();
        
        // Use copy constructor
        ScavTrap copy(original);
        std::cout << "Copy status:" << std::endl;
        copy.displayInfo();
        
        // Modify only the original
        original.takeDamage(20);
        original.beRepaired(10);
        
        std::cout << "After modifying only the original:" << std::endl;
        std::cout << "Original: ";
        original.displayInfo();
        std::cout << "Copy: ";
        copy.displayInfo();
        
        // Test specific ScavTrap function on both
        original.guardGate();
        copy.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Assignment Operator Test" << std::endl;
    {
        ScavTrap first("First");
        ScavTrap second("Second");
        
        // Modify the first ScavTrap
        first.attack("Enemy");
        first.takeDamage(25);
        first.beRepaired(10);
        first.guardGate();
        
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
    std::cout << "Inheritance Demonstration Test" << std::endl;
    {
        std::cout << "Creating a ClapTrap:" << std::endl;
        ClapTrap claptrap("Basic");
        claptrap.displayInfo();
        
        std::cout << "\nCreating a ScavTrap:" << std::endl;
        ScavTrap scavtrap("Advanced");
        scavtrap.displayInfo();
        
        // Show that both can perform base class actions
        std::cout << "\nBoth can attack:" << std::endl;
        claptrap.attack("Target1");
        scavtrap.attack("Target2");
        
        // Show unique ScavTrap ability
        std::cout << "\nOnly ScavTrap has guardGate:" << std::endl;
        scavtrap.guardGate();
    }

    return 0;
}