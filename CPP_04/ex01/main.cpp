/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:25:18 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:25:21 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	
	int	nbr_animal = 10;
	const Animal	*meta[nbr_animal];

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
