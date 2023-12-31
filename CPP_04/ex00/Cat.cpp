/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:23:04 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:23:06 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Cat::Cat( ) : Animal( )
{
	this->_type = "Cat";
	std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat( const Cat &other ) : Animal( other )
{
	std::cout << "[Cat] Copy constructor called." << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "[Cat] Default destructor called." << std::endl;
}

Cat&	Cat::operator=( const Cat &other )
{
	std::cout << "[Cat] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}


//------------- ADDITIONAL FUNCTIONS -------------//

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
