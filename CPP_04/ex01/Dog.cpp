#include "Dog.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Dog::Dog( ) : Animal( )
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog( const Dog &other ) : Animal( other )
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
