
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Enter a command: (1) ADD, (2) SEARCH or (3) EXIT" << std::endl;
	while (1)
	{
		std::cout << " >> " << std::flush;
		std::cin >> input;
		std::cout << std::endl;
		std::cout << std::endl;
		if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			phonebook.printContacts();
			phonebook.searchContact();
		}
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}