#include "Dog.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Dog::Dog(/* args */) : Animal ( "Dog" )
{
	std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog( const Dog &other ) : Animal ( other )
{
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "[Dog] Default destructor called." << std::endl;
}

Dog&	Dog::operator=( const Dog &other )
{
	std::cout << "[Dog] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}

//------------- ADDITIONAL FUNCTIONS -------------//

void	Dog::makeSound() const
{
	std::cout << "Wuff" << std::endl;
}
