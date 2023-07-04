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

	std::cout << "Creating zombie horde." << std::endl;
	std::cout << "Amount of Zombies in the horde: " << std::flush;
	std::cin >> N;
	std::cout << "Zombies' name: " << std::flush;
	std::cin >> name;

	Zombie	*horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
