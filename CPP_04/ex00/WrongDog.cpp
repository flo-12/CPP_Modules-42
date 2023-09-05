/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:06 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:07 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

WrongDog::WrongDog( ) : WrongAnimal ( )
{
	this->_type = "WrongDog";
	std::cout << "[WrongDog] Default constructor called." << std::endl;
}

WrongDog::WrongDog( const WrongDog &other ) : WrongAnimal ( other )
{
	std::cout << "[WrongDog] Copy constructor called." << std::endl;
	*this = other;
}

WrongDog::~WrongDog()
{
	std::cout << "[WrongDog] Default destructor called." << std::endl;
}

WrongDog&	WrongDog::operator=( const WrongDog &other )
{
	std::cout << "[WrongDog] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}

//------------- ADDITIONAL FUNCTIONS -------------//

void	WrongDog::makeSound() const
{
	std::cout << "Wrong Wuff" << std::endl;
}
