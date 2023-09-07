#include "RobotomyRequestForm.hpp"



//------------ ORTHODOX CANONICAL FORM ------------//

RobotomyRequestForm::RobotomyRequestForm( std::string const target )
	: AForm( "Robbymize", false, 72, 45 ), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
	: AForm ( other ), _target( other._target )
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	if ( this == &other )
		return *this;
	
	this->_target = other._target;
	this->setSigned( other.getSigned() );
	return *this;
}

//------------------ EXCEPTIONS ------------------//

//------------- GET- & SET-FUNCTIONS -------------//

//--------------- MEMBER FUNCTIONS ---------------//

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute( executor );
	std::cout << "***** DRILL DRILL DRILL *****" << std::endl;
	srand(time(NULL));
	if ( rand() % 2 == 0 )
		std::cout << this->_target << ": has been robotomized!" << std::endl;
	else
		std::cout << this->_target << ": robotonization failed :-(" << std::endl;
}

//--------------- OVERLOAD INSERTION --------------//
