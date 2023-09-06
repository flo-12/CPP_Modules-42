#include "PresidentialPardonForm.hpp"



//------------ ORTHODOX CANONICAL FORM ------------//

PresidentialPardonForm::PresidentialPardonForm( std::string const target )
	: AForm( "Presi", false, 25, 5 ), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other )
	: AForm( other ), _target( other._target )
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
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

//--------------- OVERLOAD INSERTION --------------//