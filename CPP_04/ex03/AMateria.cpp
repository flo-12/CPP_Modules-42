/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:31 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:33 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

AMateria::AMateria()
{
}

AMateria::AMateria( std::string const &type ) : _type( type )
{
}

AMateria::AMateria( const AMateria &other )
{
	*this = other;
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=( const AMateria &other )
{
	if ( this == &other )
		return *this;

	return *this;
}

//---------- GETTER- & SETTER FUNCTIONS ----------//

std::string const	&AMateria::getType() const
{
	return this->_type;
}

//------------- ADDITIONAL FUNCTIONS -------------//

AMateria*	AMateria::clone() const
{
	return (AMateria*)this;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "Won't do anything (name=" << target.getName() << ")" << std::endl;
}
