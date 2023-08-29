#include "Character.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

Character::Character()
{
}

Character::Character( const Character &other )
{

}

Character::~Character()
{
}

Character&	Character::operator=( const Character &other )
{
	if ( this == &other )
		return *this;
	
	return *this;
}


//-------------- MEMBER FUNCTIONS --------------//

std::string const	&Character::getName() const
{
	
}

void	Character::equip( AMateria* m )
{

}

void	Character::unequip( int idx )
{

}

void	Character::use( int idx, ICharacter& target )
{
	
}
