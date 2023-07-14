#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int	main()
{
	std::cout << std::endl << "------------- Animal -------------" << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "------------- Wrong Animal -------------" << std::endl;

	const WrongAnimal*	meta2 = new WrongAnimal();
	const WrongAnimal*	j2 = new WrongDog();

	std::cout << j2->getType() << " " << std::endl;
	j2->makeSound();
	meta2->makeSound();

	delete meta2;
	delete j2;

	return 0;
}
