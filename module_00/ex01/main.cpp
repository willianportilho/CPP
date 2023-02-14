#include <iostream>
#include "PhoneBook.hpp"

int main (void)
{
	std::string	command;
	PhoneBook	phone_book;

	while (1)
	{
		if (!std::cin.eof())
		{
			std::cout << "Please, enter a command (ADD, SEARCH or EXIT):" << std::endl;
			std::getline(std::cin, command);
		}
		if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "exit" << std::endl;
			std::cout << "all contacts are lost forever!" << std::endl;
			break;
		}
		else if (command == "SEARCH")
			phone_book.search_contact();
		else if (command == "ADD")
			phone_book.add_contact();
		else
			std::cout << std::endl << "Only ADD, SEARCH and EXIT are acceptable commands"
			<< std::endl << std::endl;
	}
	return (0);
}
