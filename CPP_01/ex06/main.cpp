/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:59:34 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 16:59:35 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[Error] Usage: ./harlFilter <ARG>" << std::endl;
		return (0);
	}
	Harl		harl;
	std::string	input = argv[1];

	harl.complain(argv[1]);
	return (0);
}
