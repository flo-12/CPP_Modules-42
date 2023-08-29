#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int	main()
{
	std::cout << std::endl << "------------- Animal -------------" << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << std::endl;
	std::cout << "I'm a " << dog->getType() << " " << std::endl;
	std::cout  << "I'm a " << cat->getType() << " " << std::endl;
	
	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << std::endl << "------------- Wrong Animal -------------" << std::endl;

	const WrongAnimal*	meta2 = new WrongAnimal();
	const WrongAnimal*	j2 = new WrongDog();

	std::cout << std::endl;
	std::cout << "I'm a " << j2->getType() << " " << std::endl;

	std::cout << std::endl;
	j2->makeSound();
	meta2->makeSound();

	std::cout << std::endl;
	delete meta2;
	delete j2;

	return 0;
}
