/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:57 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Cat::Cat( ) : Animal( )
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat( const Cat &other ) : Animal( other )
{
	std::cout << "[Cat] Copy constructor called." << std::endl;
	*this = other;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "[Cat] Default destructor called." << std::endl;
}

Cat&	Cat::operator=( const Cat &other )
{
	std::cout << "[Cat] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	this->_brain = new Brain( *other._brain );
	return *this;
}


//------------- ADDITIONAL FUNCTIONS -------------//

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
