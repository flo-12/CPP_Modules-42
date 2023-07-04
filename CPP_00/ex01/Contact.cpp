#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void	Contact::setIndex(int i)
{
	this->_index = i;
}

std::string	Contact::_getUserInput(std::string str)
{
	std::string	input = "";
	int			i = 0;

	for (int i = 0; i < 3; i++)
	{
		std::cout << str << std::flush;
		std::cin >> input;
		std::cout << std::endl;
		if (std::cin.good() && !input.empty())
			return (input);
		else
			std::cout << "Input invalid - try again" << std::endl;
	}
	std::cout << "Can't you enter something valid? I will use \"unicorn\" as a standard value." << std::endl;
	return ("unicorn");
}

void	Contact::initContact(void)
{
	this->_firstName = _getUserInput("First Name: ");
	this->_lastName = _getUserInput("Last Name: ");
	this->_nickname = _getUserInput("Nickname: ");
	this->_phoneNumber = _getUserInput("Phone Number: ");
	this->_darkSecret = _getUserInput("Darkest Secret: ");
	std::cout << std::endl;
}

/*
*	Displays the contact as a list of 4 columns: index,
*	first name, last name and nickname.
*	Each column is 10 characters wide. A pipe character (’|’)
*	separates them. The text is right-aligned. If the text is
*	longer than the column, it is truncated and the last
*	displayable character is replaced by a dot (’.’).
*	Nothing is displayed, if the contact is empty.
*/
void	Contact::displayContact(void)
{
	if (this->_firstName.empty() || this->_lastName.empty()
			|| this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10) << this->_firstName << std::flush;
	std::cout << "|" << std::setw(10) << this->_lastName << std::flush;
	std::cout << "|" << std::setw(10) << this->_nickname << std::flush;
	std::cout << std::endl;

	std::cout << "I STILL HAVE TO DEAL WITH VALUES WITH MORE THAN 10 CHARACTERS!!" << std::endl;
	// new function void Contact::_printLen(std::string str) to deal with longer strings
}
