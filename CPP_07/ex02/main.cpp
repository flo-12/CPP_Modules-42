/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:44:14 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 10:44:16 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];
	
	std::cout << "Initializing Array<int> and int*..." << std::endl;
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
    
	{
		// Checks for deep-copy, because for-loop out of scope wouldn't work in case of shallow copy
		std::cout << std::endl << "Test copy constructor and copy assignment operator in Scope" << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	std::cout << std::endl << "Compare each value of Array<int> and int*... (error if not equal)" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "all numbers equal - as expected" << std::endl;
    
	std::cout << std::endl << "Test exceptions..." << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "Overwriting values..." << std::endl;
	std::cout << "before: numbers[0-2]={" << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << "}" << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	std::cout << "after:  numbers[0-2]={" << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << "}" << std::endl;

	std::cout << std::endl << "Test: empty array Array<int>" << std::endl;
	Array<int>	empty(0);
	try
	{
		empty[0] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "Test: const array Array<int>" << std::endl;
	Array<int> const test(10);
	try
	{
		std::cout << "test[5]=" << test[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	delete [] mirror;

	return 0;
}
