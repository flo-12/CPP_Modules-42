/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:45:00 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/06 11:45:01 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string	input;

	std::cout << "Creating zombie on the stack..." << std::endl;
	std::cout << "Please enter the name: " << std::flush;
	std::cin >> input;

	Zombie	zombie1(input);
	zombie1.announce();

	std::cout << std::endl << "Create a zombie on the heap" << std::endl;
	std::cout << "Please enter the name: " << std::flush;
	std::cin >> input;

	Zombie	*zombie2 = newZombie(input);
	zombie2->announce();
	delete zombie2;

	std::cout << std::endl << "Calling randomChump(<name>)" << std::endl;
	std::cout << "Please enter the name: " << std::flush;
	std::cin >> input;

	randomChump(input);

	std::cout << std::endl;

	return (0);
}
