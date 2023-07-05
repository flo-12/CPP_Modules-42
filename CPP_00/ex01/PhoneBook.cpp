/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:44:09 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:44:11 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

/* addContact:
*	Saves a new contact.
*	The user is prompted to input the information of a new contact
*	one field at a time. If the input is invalid, a default value
*	is taken.
*	The contact fields are: first name, last name, nickname,
*	phone number, and darkest secret.
*/
void	PhoneBook::addContact(void)
{
	static int	i = 0;

	std::cout << "Enter the values for the new contact" << std::endl;
	this->_contacts[i % 8].setIndex(i % 8);
	this->_contacts[i % 8].initContact();
	i++;
}

/* printContacts:
*	Displays the saved contacts as a list of 4 columns: index,
*	first name, last name and nickname.
*	Each column is 10 characters wide. A pipe character (’|’)
*	separates them. The text is right-aligned. If the text is
*	longer than the column, it is truncated and the last
*	displayable character is replaced by a dot (’.’).
*/
void	PhoneBook::printContacts(void)
{
	std::cout << "---------------- PHONE BOOK ----------------" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].displayContactTable();
	std::cout << std::endl;
}

/* _validIndex:
*	Checks if the str is a valid input for the index, by checking:
*		(1) isNumeric -> all chars are numeric
*		(2) isInRange -> the int converted str is between 0 and 7
*		(3) contactExists -> contact with index "str" has entries
*	Return false if one of the checks fail and otherwise true.
*/
bool	PhoneBook::_validIndex(std::string str)
{
	std::istringstream	iss(str);
	int					index;

	if (!(iss >> index && iss.eof()))
		return (false);
	else if (index < 0 || index > 7)
		return (false);
	else if (!this->_contacts[index].hasFirstName())
		return (false);
	else
		return (true);
}

/* searchContact:
*	Prompts the user for the index of a contact to display. The
*	user has three retries if the index is out of range or wrong.
*	After the third retry, an error is displayed and the function
*	returns.
*	If the user enters a valid input, the contact information are
*	displayed, one field per line.
*/
void	PhoneBook::searchContact(void)
{
	std::string	input;
	int			index = -1;
	int			tries = 0;

	std::cout << "Please enter index of Contact to display: " << std::flush;
	std::getline(std::cin, input);
	while (!this->_validIndex(input))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		if (tries == 3)
		{
			std::cout << "Maximum number of retries reached. No contact will be displayed." << std::endl;
			return ;
		}
		std::cout << "Invalid input. Please try again: " << std::flush;
		std::getline(std::cin, input);
		tries++;
	}
	index = std::atoi(input.c_str());
	std::cout << "Details for Contact with index " << index << ":" << std::endl;
	this->_contacts[index].displayContactDetail();
	return ;
}

/* phoneBookIsEmpty:
*	Checks if the phonebook has any contacts/entries, by checking
*	if the first contact has a first name.
*	Return true if empty and otherewise false.
*/
bool	PhoneBook::phoneBookIsEmpty(void)
{
	if (this->_contacts[0].hasFirstName())
		return (false);
	else
		return (true);
}
