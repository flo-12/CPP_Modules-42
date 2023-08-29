#include "WrongAnimal.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

WrongAnimal::WrongAnimal(/* args */)
{
	std::cout << "[WrongAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
	std::cout << "[WrongAnimal] Copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Default destructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal &other )
{
	std::cout << "[WrongAnimal] Copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	return *this;
}


//---------- GETTER- & SETTER FUNCTIONS ----------//

std::string	WrongAnimal::getType() const
{
	return _type;
}


//------------- ADDITIONAL FUNCTIONS -------------//

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimals don't have a specific sound." << std::endl;
}
