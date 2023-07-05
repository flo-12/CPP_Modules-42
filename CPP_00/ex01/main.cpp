/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:44:01 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:44:04 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Enter a command: (1) ADD, (2) SEARCH or (3) EXIT" << std::endl;
	while (1)
	{
		std::cout << " >> " << std::flush;
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		else if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			if (phonebook.phoneBookIsEmpty())
				std::cout << "No Contacts in Phonebook to display" << std::endl << std::endl;
			else
			{
				phonebook.printContacts();
				phonebook.searchContact();
			}
		}
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
