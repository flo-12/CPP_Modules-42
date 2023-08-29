
#include "AAnimal.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

AAnimal::AAnimal( )
{
	std::cout << "[AAnimal] Default constructor called." << std::endl;
}

AAnimal::AAnimal( const AAnimal &other )
{
	std::cout << "[AAnimal] Copy constructor called." << std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] Default destructor called." << std::endl;
}

AAnimal&	AAnimal::operator=( const AAnimal &other )
{
	std::cout << "[AAnimal] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}


//---------- GETTER- & SETTER FUNCTIONS ----------//

std::string	AAnimal::getType() const
{
	return _type;
}


//------------- ADDITIONAL FUNCTIONS -------------//

void	AAnimal::makeSound() const
{
	std::cout << "AAnimals don't have a specific sound." << std::endl;
}
