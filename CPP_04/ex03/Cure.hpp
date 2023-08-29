#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();
	Cure( const Cure &other );
	~Cure();
	Cure&	operator=( const Cure &other );

	AMateria*	clone() const;
	void		use( ICharacter& target );
};


#endif
