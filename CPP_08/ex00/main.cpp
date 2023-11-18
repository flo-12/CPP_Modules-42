/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:39:06 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 11:39:08 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{

	int arr[] = {-12, -24, 0, 42, 13, -2183921};
	std::vector<int>	v( arr, arr + sizeof(arr) / sizeof(arr[0]) );
	std::list<int>		l( arr, arr + sizeof(arr) / sizeof(arr[0]) );

	std::cout << std::endl << "TESTS: expected -> not found" << std::endl;
	if ( easyfind( v, 8 ) != -1 || easyfind( v, -1 ) != -1 )
		std::cout << "Wrong return value" << std::endl;
	if ( easyfind( l, 8 ) != -1 || easyfind( l, -1 ) != -1 )
		std::cout << "Wrong return value" << std::endl;
	
	std::cout << std::endl << "TESTS: expected -> found it" << std::endl;
	if ( easyfind( v, 0 ) != 0 || easyfind( v, 13 ) != 0 )
		std::cout << "Wrong return value" << std::endl;
	if ( easyfind( l, 0 ) != 0 || easyfind( l, 13 ) != 0 )
		std::cout << "Wrong return value" << std::endl;
	
	
	return 0;
}
