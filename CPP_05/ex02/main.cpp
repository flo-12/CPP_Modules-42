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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
	std::cout << "------- CASES: SUCCESS PresidentialPardon -------" << std::endl;
	Bureaucrat	p1( "Klaus", 5 );
	PresidentialPardonForm	pf( "home" );
	std::cout << p1 << std::endl;
	std::cout << pf << std::endl;
	p1.signForm( pf );
	p1.executeForm( pf );

	std::cout << "------- CASES: SUCCESS RobotomyRequest -------" << std::endl;
	Bureaucrat	p2("Peter", 15);
	RobotomyRequestForm	rf( "homeAgain" );
	std::cout << p2 << std::endl;
	std::cout << rf << std::endl;
	p2.signForm( rf );
	p2.executeForm( rf );
	
	std::cout << "------- CASES: SUCCESS ShrubberyCreation -------" << std::endl;
	Bureaucrat	p3( "Wolfgang", 118 );
	ShrubberyCreationForm	sf( "Desktop" );
	std::cout << p3 << std::endl;
	std::cout << sf << std::endl;
	p3.signForm( sf );
	p3.executeForm( sf );
	}

	{
	std::cout << std::endl << "------- CASES: NO SUCCESS Exec PresidentialPardon -------" << std::endl;
	Bureaucrat	p1( "Klaus", 10 );
	Bureaucrat	p11( "Klaus the 2nd", 3 );
	PresidentialPardonForm	pf( "home2" );
	std::cout << p1 << std::endl;
	std::cout << p11 << std::endl;
	std::cout << pf << std::endl;
	p11.executeForm( pf );
	p1.signForm( pf );
	p1.executeForm( pf );

	std::cout << "------- CASES: NO SUCCESS Exec RobotomyRequest -------" << std::endl;
	Bureaucrat	p2("Peter", 55);
	Bureaucrat	p22("Peter the 2nd", 35);
	RobotomyRequestForm	rf( "homeAgain2" );
	std::cout << p2 << std::endl;
	std::cout << p22 << std::endl;
	std::cout << rf << std::endl;
	p22.executeForm( rf );
	p2.signForm( rf );
	p2.executeForm( rf );
	
	std::cout << "------- CASES: NO SUCCESS Exec ShrubberyCreation -------" << std::endl;
	Bureaucrat	p3( "Wolfgang", 140 );
	Bureaucrat	p33( "Wolfgang the 2nd", 14 );
	ShrubberyCreationForm	sf( "Desktop2" );
	std::cout << p3 << std::endl;
	std::cout << p33 << std::endl;
	std::cout << sf << std::endl;
	p33.executeForm( sf );
	p3.signForm( sf );
	p3.executeForm( sf );
	}
		
	return (0);
}