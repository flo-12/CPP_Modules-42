#include "ShrubberyCreationForm.hpp"



std::string const ShrubberyCreationForm::_tree[1] = {
"               ,@@@@@@@,\n"\
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
"   `&%\\ ` /%&'    |.|        \\ '|8'\n" \
"       |o|        | |         | |\n" \
"       |.|        | |         | |\n" \
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
} ;


//------------ ORTHODOX CANONICAL FORM ------------//

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) 
	: AForm( "shrubby_shrubbery", false, 145, 137 ), _target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	
}


//------------------ EXCEPTIONS ------------------//

//------------- GET- & SET-FUNCTIONS -------------//

//--------------- MEMBER FUNCTIONS ---------------//

//--------------- OVERLOAD INSERTION --------------//
