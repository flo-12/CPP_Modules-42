#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
public:
	PhoneBook(/* args */);
	~PhoneBook();

	void	addContact(void);
	void	printContacts(void);
	void	searchContact(void);
};

#endif