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

int	main()
{
	std::cout << "GRADE TO LOW AND GRADE TO HIGH:" << std::endl;
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

	std::cout << std::endl << "CREATE BUREAUCRAT WITH VALID GRADES" << std::endl;
	try
	{
		Bureaucrat	p3( "Tom", 1 );
		std::cout << p3 << std::endl;
		p3.incGrade();
		std::cout << p3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	p4( "Jose", 150 );
		std::cout << p4 << std::endl;
		p4.decGrade();
		std::cout << p4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}