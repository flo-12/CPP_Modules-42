#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
private:
	/* data */
public:
	Cat(/* args */);
	Cat( const Cat &other );
	~Cat();
	Cat&	operator=( const Cat &other );

	void	makeSound() const;
};


#endif

