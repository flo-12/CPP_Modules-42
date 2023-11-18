/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:03 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 18:19:05 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

/* main:
*	The program takes a sequence of positive integers as arguments.
*		- If no arguments are passed or if one of the arguments is not a positive integer, the program displays an error.
*	The numbers are then sorted by the PmergeMe class with the merge-insert sort algorithm (Ford-Johnson algorithm).
*		- two different functions (with different containers) from the PmergeMe class are used to sort the numbers.
*	The following is displayed in the prompt:
*		- 1st line: "Before: [arg1] [arg2] [arg3] ... [argn]"
*		- 2nd line: "After: [arg1] [arg2] [arg3] ... [argn]"
*		- 3rd line: "Time to process a range of [n] elements with std::[container]: [time] us"
*		- 4th line: "Time to process a range of [n] elements with std::[container]: [time] us"
*/
int	main( int argc, char **argv )
{
	// Check if arguments are passed
	if (argc < 2)
	{
		std::cout << "Error: No arguments passed." << std::endl;
		return (1);
	}

	// Check if all arguments are positive integers
	for (int i = 1; i < argc; i++)
	{
		if (std::atoi(argv[i]) <= 0)
		{
			std::cout << "Error: Argument " << i << " (" << argv[i] << ") is not a positive integer." << std::endl;
			return (1);
		}
	}

	// Sort the numbers
	PmergeMe	pmm;
	pmm.sortList( argc - 1, argv + 1 );
	pmm.sortVector( argc - 1, argv + 1 );
	pmm.printResults();

	return 0;
}
