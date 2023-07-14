#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
private:
	/* data */
public:
	Dog(/* args */);
	Dog( const Dog &other );
	~Dog();
	Dog&	operator=( const Dog &other );

	void	makeSound() const;
};





#endif
