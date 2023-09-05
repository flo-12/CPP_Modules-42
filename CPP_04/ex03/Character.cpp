/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:44 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:46 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

Character::Character() : _name( "default" )
{
	for ( int i = 0; i < 4; i++ )
		_materia[i] = NULL;
}

Character::Character( std::string name ) : _name( name )
{
	for ( int i = 0; i < 4; i++ )
		_materia[i] = NULL;
}

Character::Character( const Character &other )
{
	this->_name = other._name;
	for ( int i = 0; i < 4; i++ ) {
		if ( this->_materia[i] )
			delete this->_materia[i];
		if ( other._materia[i] )
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

Character::~Character()
{
	for ( int i = 0; i < 4; i++ ) {
		if ( _materia[i] )
			delete _materia[i];
	}
}

Character&	Character::operator=( const Character &other )
{
	if ( this == &other )
		return *this;
	
	this->_name = other._name;
	for ( int i = 0; i < 4; i++ ) {
		if ( this->_materia[i] )
			delete this->_materia[i];
		if ( other._materia[i] )
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	return *this;
}


//-------------- MEMBER FUNCTIONS --------------//

std::string const	&Character::getName() const
{
	return this->_name;
}

void	Character::equip( AMateria* m )
{
	for ( int i = 0; i < 4; i++ ) {
		if ( _materia[i] == NULL )
		{
			_materia[i] = m;
			return ;
		}
	}
}

void	Character::unequip( int idx )
{
	if ( (idx > 3 || idx < 0) || _materia[idx] == NULL )
		return ;

	_materia[idx] = NULL;
	for ( int i = idx + 1; i < 4; i++) {
		if ( _materia[i] == NULL )
			break ;
		_materia[i - 1] = _materia[i];
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if ( _materia[idx] == NULL )
		return ;

	_materia[idx]->use(target);
}
