/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:46 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:48 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

Serializer::Serializer()
{}

Serializer::Serializer( const Serializer &other )
{
	*this = other;
}

Serializer::~Serializer()
{}

Serializer&	Serializer::operator=( const Serializer &other )
{
	(void)other;
	return *this;
}


//--------------- MEMBER FUNCTIONS ---------------//

uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast< uintptr_t >( ptr );
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast< Data* >( raw );
}
