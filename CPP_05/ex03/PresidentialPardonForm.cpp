/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:58:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:58:13 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

PresidentialPardonForm::PresidentialPardonForm( std::string const target )
	: AForm( "Presi", 25, 5 ), _target(target)
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


//--------------- MEMBER FUNCTIONS ---------------//

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
