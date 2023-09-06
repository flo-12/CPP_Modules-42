#include "RobotomyRequestForm.hpp"



//------------ ORTHODOX CANONICAL FORM ------------//

RobotomyRequestForm::RobotomyRequestForm( std::string const target )
	: AForm( "Robbymize", false, 75, 45 ), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//------------------ EXCEPTIONS ------------------//

//------------- GET- & SET-FUNCTIONS -------------//

//--------------- MEMBER FUNCTIONS ---------------//

//--------------- OVERLOAD INSERTION --------------//