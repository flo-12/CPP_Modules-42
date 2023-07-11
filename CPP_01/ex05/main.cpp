/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:11:59 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:12:01 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl		harl;
	std::string	input;

	do
	{
		std::cout << "Enter a level: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Something with the input went wrong. Try again..." << std::endl;
		}
		else
			harl.complain(input);
	} while (input.compare("exit"));
	return (1);
}
