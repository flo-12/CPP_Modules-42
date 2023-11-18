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
#include "Intern.hpp"

int	main()
{
	Intern	intern;
	AForm	*pf;
	AForm	*rf;
	AForm	*sf;

	std::cout << std::endl << "------- CASES: Intern creates forms -------" << std::endl;
	pf = intern.makeForm( "Something New", "home" );
	if ( !pf )
		pf = intern.makeForm( "PresidentialPardonForm", "home" );
	rf = intern.makeForm( "RobotomyRequestForm", "homeAgain" );
	sf = intern.makeForm( "ShrubberyCreationForm", "Desktop" );

	std::cout << std::endl << "------- CASES: SUCCESS PresidentialPardon -------" << std::endl;
	Bureaucrat	p1( "Klaus", 5 );
	//PresidentialPardonForm	pf( "home" );
	std::cout << p1 << std::endl;
	std::cout << *pf << std::endl;
	p1.signForm( *pf );
	p1.executeForm( *pf );

	std::cout << std::endl << "------- CASES: SUCCESS RobotomyRequest -------" << std::endl;
	Bureaucrat	p2("Peter", 15);
	//RobotomyRequestForm	rf( "homeAgain" );
	std::cout << p2 << std::endl;
	std::cout << *rf << std::endl;
	p2.signForm( *rf );
	p2.executeForm( *rf );
	
	std::cout << std::endl << "------- CASES: SUCCESS ShrubberyCreation -------" << std::endl;
	Bureaucrat	p3( "Wolfgang", 118 );
	//ShrubberyCreationForm	sf( "Desktop" );
	std::cout << p3 << std::endl;
	std::cout << *sf << std::endl;
	p3.signForm( *sf );
	p3.executeForm( *sf );

	delete pf;
	delete rf;
	delete sf;

	return (0);
}
