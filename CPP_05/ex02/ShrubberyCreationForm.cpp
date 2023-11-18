/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:44 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:08:46 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


std::string const ShrubberyCreationForm::_tree[2] = {
	"               ,@@@@@@@,\n"\
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
	"   `&%\\ ` /%&'    |.|        \\ '|8'\n" \
	"       |o|        | |         | |\n" \
	"       |.|        | |         | |\n" \
	"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n",
	"         *\n" \
	"        /|\\\n" \
	"       /*|O\\\n" \
	"      /*/|\\*\\\n" \
	"     /X/O|*\\X\\\n" \
	"    /*/X/|\\X\\*\\\n" \
	"   /O/*/X|*\\O\\X\\\n" \
	"  /*/O/X/|\\X\\O\\*\\\n" \
	" /X/O/*/X|O\\X\\*\\O\\\n" \
	"/O/X/*/O/|\\X\\*\\O\\X\\\n" \
	"        |X|\n" \
	"        |X|\n"
} ;


//------------ ORTHODOX CANONICAL FORM ------------//

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) 
	: AForm( "shrubbery", 145, 137 ), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other )
	: AForm( other ), _target( other._target )
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	if ( this == &other )
		return *this;

	this->_target = other._target;
	return *this;
}


//------------------ EXCEPTIONS ------------------//

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "ShrubberyCreationFormException: Open File failed";
}

const char*	ShrubberyCreationForm::WriteFileException::what() const throw()
{
	return "ShrubberyCreationFormException: Write File failed";
}


//--------------- MEMBER FUNCTIONS ---------------//

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute( executor );
	std::string const	shrubName = this->_target + "_shrubbery";
	std::ofstream	outputFile( shrubName.c_str() );
	
	if ( !outputFile.is_open() || outputFile.bad() )
		throw ShrubberyCreationForm::OpenFileException();
	srand(time(NULL));
	if ( std::rand() % 2 == 0 )
		outputFile << this->_tree[0];
	else
		outputFile << this->_tree[1];
	outputFile.close();
}

