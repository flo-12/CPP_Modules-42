#include "Brain.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Brain::Brain()
{
	std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain( const Brain &other )
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "[Brain] Default destructor called" << std::endl;
}

Brain&	Brain::operator=( const Brain &other )
{
	std::cout << "[Brain] Copy assignment operator called" << std::endl;
	
	if ( this == &other )
		return *this;

	for ( int i = 0; i < 100; i++ )
		this->_ideas[i] = other._ideas[i];
	return *this;
}
