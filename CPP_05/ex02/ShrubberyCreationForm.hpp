#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream> 
# include <stdlib.h>
# include <time.h> 
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();

	std::string					_target;
	static std::string const	_tree[2];
public:
	ShrubberyCreationForm( std::string const target );
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm &other );

	class OpenFileException : public std::exception {
		virtual const char* what() const throw();
	};
	class WriteFileException : public std::exception {
		virtual const char* what() const throw();
	};

	void	execute(Bureaucrat const & executor) const;
};



#endif