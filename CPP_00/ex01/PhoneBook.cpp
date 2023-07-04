
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
	std::cout << "-------------- PHONE BOOK --------------" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].displayContact();
	std::cout << std::endl;
}

/* searchContact:
*	Prompts the user for the index of a contact to display. The
*	user has three retires if the index is out of range or wrong.
*	After the third retry, an error is displayed and the function
*	returns.
*	If the user enters a valid input, the contact information are
*	displayed, one field per line.
*/
void	PhoneBook::searchContact(void)
{
	std::cout << "YET TO BE IMPLEMENTED" << std::endl;
}
