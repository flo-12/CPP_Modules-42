/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:21:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:21:56 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "------- CASES WITH WRONG GRADE -------" << std::endl;
	try
	{
		Bureaucrat	p1( "Klaus", 0 );
		std::cout << p1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	p2("Peter", 156);
		std::cout << p2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	f1("formly", -1, 20);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	f2("formly", 200, 20);
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	f3("formly", 100, -20);
		std::cout << f3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	f4("formly", 100, 198);
		std::cout << f4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << std::endl << std::endl << "------- CASES GRADE TOO LOW TO SIGN -------" << std::endl;
	try
	{
		Bureaucrat	p3( "Tom", 100 );
		Form		f5( "formly", 50, 10 );
		std::cout << p3 << std::endl;
		std::cout << f5 << std::endl;
		p3.signForm( f5 );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << std::endl << "------- CASE SUCCESS SIGN -------" << std::endl;
	try
	{
		Bureaucrat	p4( "Eddy", 10 );
		Form		f6( "formly", 50, 10 );
		std::cout << p4 << std::endl;
		std::cout << f6 << std::endl;
		p4.signForm( f6 );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}