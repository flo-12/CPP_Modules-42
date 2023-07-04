#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
#include <iomanip>

class Contact
{
private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkSecret;
	std::string	_getUserInput(std::string str);
public:
	Contact(/* args */);
	~Contact();

	void	setIndex(int i);
	void	initContact(void);
	void	displayContact(void);
};

#endif