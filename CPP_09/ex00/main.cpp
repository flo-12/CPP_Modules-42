/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:58:36 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 12:58:38 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

/* main:
*	The program outputs the value of a certain amount of bitcoin in a certain date
*	- The program reads the database "data.csv" which represents bitcoin price over time
*		- Each line in this file must use the format: "date | value"
*		- The date is in the format: "YYYY-MM-DD"
*		- The value is either a float or an integer, between 0 and 1000
*	- The program takes as input a 2nd database (file as argument), storing the different prices/dates to evaluate.
*	The program displays the result of the value multiplied by the exchange rate according to the date indicated in the database on the standard output.
*	- Possible errors are handled with an appropriate message.
*	- If the date used in the input does not exist in the database, the closest date before the input date is used.
*/
int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./bitcoin [file]" << RESET << std::endl;
		return (1);
	}
	BitcoinExchange bitcoin( argv[1] );
	bitcoin.run();
	return (0);
}
