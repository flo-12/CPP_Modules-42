/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:57 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:59 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

Cure::Cure() : AMateria( "cure" )
{
}

Cure::Cure( const Cure &other ) : AMateria( "cure" )
{
	*this = other;
}

Cure::~Cure()
{
}

Cure&	Cure::operator=( const Cure &other )
{
	if ( this == &other )
		return *this;

	return *this;
}


//-------------- MEMBER FUNCTIONS --------------//

AMateria*	Cure::clone() const
{
	return new Cure( *this );
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
