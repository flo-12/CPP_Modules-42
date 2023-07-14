#include "Animal.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Animal::Animal(/* args */)
{
	std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal( std::string type ) : _type( type )
{
	std::cout << "[Animal] Default constructor called (set name)." << std::endl;
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
