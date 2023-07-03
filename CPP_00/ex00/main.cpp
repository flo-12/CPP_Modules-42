/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:07:49 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:07:52 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie	zombi1(name);

	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie	*zombi2 = newZombie(name);
	zombi2->announce();
	delete zombi2;

	std::cout << "Calling randomChump(unicorn)." << std::endl;
	randomChump("unicorn");
	return (0);
}
