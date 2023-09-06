#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();

	std::string	_target;
public:
	RobotomyRequestForm( std::string const target );
	RobotomyRequestForm( const RobotomyRequestForm &other );
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=( const RobotomyRequestForm &other );
};



#endif
