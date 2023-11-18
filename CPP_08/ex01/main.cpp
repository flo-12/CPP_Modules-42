/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:39:23 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/14 12:39:25 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

std::vector<int>	createvector( unsigned int len )
{
	srand(time(NULL));
	std::vector<int>	v;

	for ( unsigned int i = 0; i < len; i++ ) {
		v.push_back( rand() );
	}

	return v;
}

int	main()
{
	{
	std::cout << std::endl << "******** TEST: small span ********" << std::endl;
	Span	sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	{
	std::cout << std::endl << "******** TEST: min/min int ********" << std::endl;
	Span	sp = Span(2);
	
	sp.addNumber(std::numeric_limits<int>::min());
	sp.addNumber(std::numeric_limits<int>::max());

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	{
	std::cout << std::endl << "******** TEST: span.size()=20000 ********" << std::endl;
	std::vector<int>	v = createvector( 20000 );
	Span	spBig = Span( 20000 );

	spBig.addNumber(42);
	spBig.addNumber(-42);
	std::cout << "size=" << spBig.getSize() << std::endl;
	
	try
	{
		spBig.addNumber( v.begin(), v.end() );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "size=" << spBig.getSize() << std::endl;
	try
	{
		spBig.addNumber( v.begin() + 2, v.end() );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		spBig.addNumber( 0 );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "spBig[0,1,2]=" << spBig[0] << ", " << spBig[1] << ", " << spBig[2] << " | size=" << spBig.getSize() << std::endl;
	std::cout << "shortest span: " << spBig.shortestSpan() << std::endl;
	std::cout << "longest span: " << spBig.longestSpan() << std::endl;
	}

	return 0;
}
