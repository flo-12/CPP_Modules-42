/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:39:25 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:39:26 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

/* generate:
*	Randomly instanciates A, B or C and returns 
*	the instance as a Base pointer.
*/
Base*	generate( void )
{
	srand(time(NULL));
	int	nbr = rand();
	if ( nbr % 3 == 0 ) {
		std::cout << "Generate ... A" << std::endl;
		return new A;
	}
	else if ( nbr % 3 == 1 ) {
		std::cout << "Generate ... B" << std::endl;
		return new B;
	}
	else if ( nbr % 3 == 2 ) {
		std::cout << "Generate ... C" << std::endl;
		return new C;
	}
	else {
		std::cout << "Generate .... nothing (error)" << std::endl;
		return NULL;
	}
}

/* identify:
*	Prints the actual type of the object pointed to by p: 
*		"A", "B" or "C".
*/
void	identify( Base* p )
{
	if ( p == NULL )
		return ;
	std::cout << "identified by Base *p: ";
	if ( dynamic_cast< A* >( p ) )
		std::cout << "A";
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B";
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C";
	else
		std::cout << "ERROR: nothing identified";
	std::cout << std::endl;
}

/* identify:
*	Prints the actual type of the object pointed to by p: 
*		"A", "B" or "C"
*	Using a pointer inside this function is forbidden.
*/
void	identify( Base& p )
{
	std::cout << "identified by Base &p: ";
	try
	{
		(void)dynamic_cast< A& >( p );
		std::cout << "A";
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast< B& >( p );
		std::cout << "B";
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast< C& >( p );
		std::cout << "C";
	}
	catch(const std::exception& e) {}
	std::cout << std::endl;
}

int	main()
{
	Base	*b1 = generate();

	identify( b1 );
	identify( *b1 );

	delete b1;

	return 0;
}


