
#include "Cat.hpp"
#include "Dog.hpp"


int	main()
{
	/* std::cout << std::endl << "------------- Test Instantiation -------------" << std::endl;
	AAnimal	test; */
	
	int	nbr_animal = 10;
	const AAnimal	*meta[nbr_animal];

	std::cout << std::endl << "------------- Create Animals -------------" << std::endl;
	for ( int i = 0; i < nbr_animal; i++ ) {
		if ( i % 2 == 0 )
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		std::cout << "I am a " << meta[i]->getType() << std::endl;
	}

	std::cout << std::endl << "------------- Delete Animals -------------" << std::endl;
	for ( int i = 0; i < nbr_animal; i++ )
		delete meta[i];

	std::cout << std::endl << "------------- Test deep copies -------------" << std::endl;
	Dog	basic;
	{
		Dog	tmp = basic;
		std::cout << "end of scope" << std::endl;
	}
	std::cout << "end of main" << std::endl;


	return 0;
}
