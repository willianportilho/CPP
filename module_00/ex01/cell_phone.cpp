#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main (void)
{
	std::string	command;
	PhoneBook	phone_book;

	std::cout << "Please, enter a command (ADD, SEARCH or EXIT)" << std::endl;
	while (1)
	{
		std::cout << "cellphone: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "SEARCH")
			std::cout << "Searck is ok" << std::endl;
		else if (command == "ADD")
			std::cout << "Add is ok" << std::endl;
		else
			std::cout << "Only ADD, SEARCH and EXIT are acceptable commands" << std::endl;
	}
	return (0);
}
