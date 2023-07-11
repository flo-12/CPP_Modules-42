/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:11:37 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:11:39 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error usage: ./Replace <filename> <string_to_find> <string_replace>" << std::endl;
		return (1);
	}
	File	file(argv[1]);
	file.myReplace(argv[2], argv[3]);
	return (0);
}
