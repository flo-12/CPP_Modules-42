/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:27 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:32 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Animal::Animal( )
{
	std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal( const Animal &other )
{
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "[Animal] Default destructor called." << std::endl;
}

Animal&	Animal::operator=( const Animal &other )
{
	std::cout << "[Animal] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}


//---------- GETTER- & SETTER FUNCTIONS ----------//

std::string	Animal::getType() const
{
	return _type;
}


//------------- ADDITIONAL FUNCTIONS -------------//

void	Animal::makeSound() const
{
	std::cout << "Animals don't have a specific sound." << std::endl;
}
