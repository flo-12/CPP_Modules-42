/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:05 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:07 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Dog::Dog( ) : AAnimal( )
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog( const Dog &other ) : AAnimal( other )
{
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = other;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "[Dog] Default destructor called." << std::endl;
}

Dog&	Dog::operator=( const Dog &other )
{
	std::cout << "[Dog] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	this->_brain = new Brain( *other._brain );
	return *this;
}

//------------- ADDITIONAL FUNCTIONS -------------//

void	Dog::makeSound() const
{
	std::cout << "Wuff" << std::endl;
}
