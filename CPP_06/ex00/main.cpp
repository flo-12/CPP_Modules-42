/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:08 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:09 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Wrong number of arguments - Please try again" << std::endl;
		return 1;
	}

	ScalarConverter	s;
	s.convert( argv[1] );
	return 0;
}
