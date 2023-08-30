#include "MateriaSource.hpp"

//---- ORTHODOX CANONICAL FORM & CONSTRUCTOR ----//

MateriaSource::MateriaSource()
{
	for ( int i = 0; i < 4; i++ ) {
		_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
	for ( int i = 0; i < 4; i++ ) {
		if ( this->_materia[i] != NULL )
			delete this->_materia[i];
		if ( other._materia[i] != NULL )
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for ( int i = 0; i < 4; i++ ) {
		if ( _materia[i] != NULL )
			delete _materia[i];
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource &other )
{
	if ( this == &other )
		return *this;
	
	for ( int i = 0; i < 4; i++ ) {
		if ( this->_materia[i] != NULL )
			delete this->_materia[i];
		if ( other._materia[i] != NULL )
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	return *this;
}

//-------------- MEMBER FUNCTIONS --------------//

void	MateriaSource::learnMateria( AMateria* m )
{
	for ( int i = 0; i < 4; i++) {
		if ( _materia[i] == NULL )
		{
			_materia[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for ( int i = 3; i >= 0; i-- ) {
		if ( _materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}