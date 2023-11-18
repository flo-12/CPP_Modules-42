/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:57:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:57:58 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


std::string	Intern::_forms[3] = {
    "PresidentialPardonForm",
    "RobotomyRequestForm",
    "ShrubberyCreationForm"
};


//------------ ORTHODOX CANONICAL FORM ------------//

Intern::Intern()
{
	_formCreator[0] = _createPPF;
	_formCreator[1] = _createRRF;
	_formCreator[2] = _createSCF;
}

Intern::Intern( const Intern &other )
{
	_formCreator[0] = _createPPF;
	_formCreator[1] = _createRRF;
	_formCreator[2] = _createSCF;
	*this = other;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=( const Intern &other )
{
	(void)other;
	return *this;
}


//--------------- MEMBER FUNCTIONS ---------------//

AForm*	Intern::makeForm( const std::string form, const std::string target )
{
	for( int i = 0; i < 3; i++ ) {
		if ( _forms[i] == form )
			return _formCreator[i]( target );
	}
	std::cout << "Form \"" << form << "\" not found -> nothing created" << std::endl;
	return NULL;
}

AForm*	Intern::_createPPF( const std::string target )
{
	std::cout << "Intern Creates PresidentialPardonForm" << std::endl;
	return new PresidentialPardonForm( target );
}

AForm*	Intern::_createRRF( const std::string target )
{
	std::cout << "Intern Creates RobotomyRequestForm" << std::endl;
	return new RobotomyRequestForm( target );
}

AForm*	Intern::_createSCF( const std::string target )
{
	std::cout << "Intern Creates ShrubberyCreationForm" << std::endl;
	return new ShrubberyCreationForm( target );
}
