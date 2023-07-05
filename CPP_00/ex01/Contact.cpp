/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:43:45 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:43:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

/* setIndex:
*	Sets the index of the contact.
*/
void	Contact::setIndex(int i)
{
	this->_index = i;
}

/* _getUserInput:
*	Displays the contact as a list of 4 columns: index, first
*	name, last name and nickname.
*	Each column is 10 characters wide. A pipe character (’|’)
*	separates them. The text is right-aligned. If the text is
*	longer than the column, it is truncated and the last
*	displayable character is replaced by a dot (’.’).
*/
std::string	Contact::_getUserInput(std::string str)
{
	std::string	input;

	for (int i = 0; i < 3; i++)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Input failed - try again" << std::endl;
		}
		else if (input.empty())
			std::cout << "Empty line entered - try again" << std::endl;
		else
			return (input);
	}
	std::cout << "Can't you enter something valid? I will use \"unicorn\" as a standard value." << std::endl;
	return ("unicorn");
}

/* initContact:
*	The user is prompted to input the information of a new contact
*	one field at a time. If the input is invalid, a default value
*	is taken.
*	The contact fields are: first name, last name, nickname,
*	phone number, and darkest secret.
*/
void	Contact::initContact(void)
{
	this->_firstName = _getUserInput("First Name: ");
	this->_lastName = _getUserInput("Last Name: ");
	this->_nickname = _getUserInput("Nickname: ");
	this->_phoneNumber = _getUserInput("Phone Number: ");
	this->_darkSecret = _getUserInput("Darkest Secret: ");
	std::cout << std::endl;
}

/* _printLen:
*	If the string (argument) is longer than the 10 chars, it
*	is truncated and the last displayable character is replaced
*	by a dot (’.’). If the string is short, nothing is done.
*	Return the new, truncated string.
*/
std::string	Contact::_printLen(std::string str)
{
	std::string	result;
	int			i = 0;

	for (std::string::iterator it = str.begin(); it < str.end(); it++)
	{
		result.push_back(*it);
		i++;
		if (i == 9)
		{
			result.push_back('.');
			break ;
		}
	}
	return (result);
}

/* displayContactTable:
*	Displays the contact as a list of 4 columns: index,
*	first name, last name and nickname.
*	Each column is 10 characters wide. A pipe character (’|’)
*	separates them. The text is right-aligned. If the text is
*	longer than the column, it is truncated and the last
*	displayable character is replaced by a dot (’.’).
*	Nothing is displayed, if the contact is empty.
*/
void	Contact::displayContactTable(void)
{
	if (this->_firstName.empty() || this->_lastName.empty()
			|| this->_nickname.empty())
		return ;
	std::cout << "|" << std::right << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::right << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
	std::cout << "|" << std::right << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
	std::cout << "|" << std::right << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

/* displayContactDetail:
*	Display the contact with each information line by line.
*	Nothing is displayed if the contact is empty.
*/
void	Contact::displayContactDetail(void)
{
	if (this->_firstName.empty() || this->_lastName.empty()
			|| this->_nickname.empty())
		return ;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phonenumber: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkSecret << std::endl;
	std::cout << std::endl;
}

/* hasFirstName:
*	Returns true of the current Contact has a first name
*	and false if not.
*/
bool	Contact::hasFirstName(void)
{
	if (this->_firstName.empty())
		return (false);
	else
		return (true);
}

/* getFirstName:
*	Return the value of the attribute _firstName.
*/
std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}
