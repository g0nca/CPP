#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include "MutantStack.hpp" // Certifique-se de que o nome do ficheiro está correto

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "        Basic Tests				      " << std::endl;
    std::cout << "========================================" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Actual Top (must be 17): " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Length after pop (must be 1): " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n--- Test 1: Standard Iterator (MutantStack) ---" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;


    std::cout << "\n========================================" << std::endl;
    std::cout << "        Testing with others iterators   " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- Teste 2: Reverse Iterator ---" << std::endl;
    // Iterador reverso percorre de trás para a frente
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << " "; // Output esperado: 0 737 5 3 5
        ++rit;
    }
    std::cout << std::endl;


    std::cout << "\n--- Teste 3: Const Iterator ---" << std::endl;
    // Para testar iteradores constantes, precisamos de uma cópia const da stack
    const MutantStack<int> const_mstack(mstack);
    
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    while (cit != cite) {
        std::cout << *cit << " ";
        // *cit = 42;
        ++cit;
    }
    std::cout << std::endl;


    std::cout << "\n--- Teste 4: Const Reverse Iterator ---" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    while (crit != crite) {
        std::cout << *crit << " "; // Output esperado: 0 737 5 3 5
        ++crit;
    }
    std::cout << std::endl;

    return 0;
}

/* int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */