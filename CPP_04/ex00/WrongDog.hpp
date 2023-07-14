#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
private:
	/* data */
public:
	WrongDog(/* args */);
	WrongDog( const WrongDog &other );
	~WrongDog();
	WrongDog&	operator=( const WrongDog &other );

	void	makeSound() const;
};


#endif
