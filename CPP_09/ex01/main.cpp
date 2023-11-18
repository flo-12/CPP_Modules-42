/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:16:17 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 17:16:19 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* main:
*	The program takes an inverted Polish mathematical expression as an argument.
*	The program evaluates the expression and displays the result on the standard output.
*	If the expression is not valid, the program displays an error message on the standard output.
*	An expression is considered as valid if:
*		- all the operands are between 0 and 10
*		- there are as many operators as there are operands minus 1
*	Operations with the following operators are supported: +, -, * and /
*	A std::stack is used in the RPN class to evaluate the expression.
*/
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <inverted polish mathematical expression>" << std::endl;
		return (1);
	}
	RPN	rpn;
	try
	{
		std::cout << rpn.eval( argv[1] ) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
