/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:08:46 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:08:48 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name;
	int			N;

	std::cout << "Creating a zombie horde..." << std::endl;
	std::cout << "Please enter a name: " << std::flush;
	std::cin >> name;
	do
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Enter the number of zombies: " << std::flush;
		std::cin >> N;
	} while (!std::cin.good());

	std::cout << std::endl << "Zombies are created and announce themselves..." << std::endl;
	Zombie	*horde = zombieHorde( N, name );
	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::endl << "Deleting the zombie horde again..." << std::endl;
	delete [] horde;
	
	std::cout << std::endl;
	
	return (0);
}
