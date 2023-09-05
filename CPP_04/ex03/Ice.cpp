/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:09 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:27:11 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

Ice::Ice() : AMateria( "ice" )
{
}

Ice::Ice( const Ice &other ) : AMateria( "ice" )
{
	*this = other;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=( const Ice &other )
{
	if ( this == &other )
		return *this;
	
	return *this;
}


//-------------- MEMBER FUNCTIONS --------------//

AMateria*	Ice::clone() const
{
	return new Ice( *this );
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
