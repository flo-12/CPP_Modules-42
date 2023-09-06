#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();

	std::string					_target;
	static std::string const	_tree[1];
public:
	ShrubberyCreationForm( std::string const target );
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm &other );
};



#endif