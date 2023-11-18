/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:33 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 10:08:35 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int	main()
{
	std::cout << std::endl << "----------- TEST WITH INT -----------" << std::endl;
	int	a[ 3 ] = {42, 1, 0};
	iter<int>(a, 3, ::print);

	std::cout << std::endl << "----------- TEST WITH STRING -----------" << std::endl;
	char	str[ 4 ] = {'?', 'a', 'b', 'c'};
	iter<char>(str, 4, ::print);
	
	std::cout << std::endl << "----------- TEST WITH FLOAT -----------" << std::endl;
	float	f[ 6 ] = {-7.1, 42, -128.32, 123.123, 0.1, 100.99};
	iter<float>(f, 6, ::print);

	return 0;
}
