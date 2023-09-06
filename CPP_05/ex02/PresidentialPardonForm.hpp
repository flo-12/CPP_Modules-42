#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	
	std::string	_target;
public:
	PresidentialPardonForm( std::string const target );
	PresidentialPardonForm( const PresidentialPardonForm &other );
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=( const PresidentialPardonForm &other );
};





#endif