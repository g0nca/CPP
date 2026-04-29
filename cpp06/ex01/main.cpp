#include "Serializer.hpp"

int	main(int argc , char *argv[]) 
{
	if (argc != 3) {
		std::cout << "Correct usage: ./Serializer <string> <number>" << std::endl;
		return (1);
	}

	std::string	name = argv[1], number = argv[2];
	if (name.empty() || number.empty() || number.length() > 5)
		return (1);

	Data		data = (Data){name, strtol(number.c_str(), NULL, 10)};

	uintptr_t	s = Serializer::serialize(&data);

	std::cout << "Original address  => " << &data << std::endl;
	std::cout << "Serialized (dec)  => " << s << std::endl;
	std::cout << "Serialized (hex)  => 0x" << std::hex << s << std::dec << std::endl;
	std::cout << "Deserialized ptr  => " << Serializer::deserialize(s) << std::endl;

	std::cout << "Data [" << data.name << ", " << data.value << "]" << std::endl;
	return (0);
}