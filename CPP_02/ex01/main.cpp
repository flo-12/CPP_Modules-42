/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:48:57 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:48:58 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );
	Fixed const e( -5 );
	Fixed const f( -42.42f );
	//Fixed const g( 2147483648 );	// error in compilation: "call of overloaded ‘Fixed(long int)’ is ambiguous"

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;

	return 0;
}
