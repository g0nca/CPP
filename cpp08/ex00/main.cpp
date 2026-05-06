#include "easyfind.hpp"

int	main( void ) {
	std::vector<int> n;
	n.push_back(0);
	n.push_back(5);
	n.push_back(4);
	n.push_back(3);
	n.push_back(2);
	n.push_back(1);
	try {
		std::cout << *(::easyfind(n, 5)) << std::endl;
		std::cout << *(::easyfind(n, 2)) << std::endl;

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		const std::vector<int> const_vector(n);
		std::cout << "Const Vectors" << std::endl;
		std::cout << *(::easyfind(const_vector, 5)) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}