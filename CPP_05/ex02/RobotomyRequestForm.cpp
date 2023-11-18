/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:31 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:08:33 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"



//------------ ORTHODOX CANONICAL FORM ------------//

RobotomyRequestForm::RobotomyRequestForm( std::string const target )
	: AForm( "Robbymize", 72, 45 ), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
	: AForm ( other ), _target( other._target )
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	if ( this == &other )
		return *this;
	
	this->_target = other._target;
	this->setSigned( other.getSigned() );
	return *this;
}


//--------------- MEMBER FUNCTIONS ---------------//

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute( executor );
	std::cout << "***** DRILL DRILL DRILL *****" << std::endl;
	srand(time(NULL));
	if ( rand() % 2 == 0 )
		std::cout << this->_target << ": has been robotomized!" << std::endl;
	else
		std::cout << this->_target << ": robotonization failed :-(" << std::endl;
}

