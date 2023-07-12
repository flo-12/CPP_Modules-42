/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:02:38 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 13:02:40 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->setHitPoints( 100 );
	this->setEnergyPoints( 100 );
	this->setAttackDamage( 30 );

	std::cout << "[FragTrap] " << this->getName() << " created" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap( other )
{
	std::cout << "[FragTrap] Copy constructor for " << other.getName()
				<< " called" << std::endl;

	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << this->getName() << " destroyed" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap &other )
{
	std::cout << "[FragTrap] Copy assignment operator for " << other.getName()
				<< " called" << std::endl;

	if (this == &other)
		return ( *this );
	this->setName( other.getName() );
	this->setHitPoints( other.getHitPoints() );
	this->setEnergyPoints( other.getEnergyPoints() );
	this->setAttackDamage( other.getAttackDamage() );
	return ( *this );
}


//------------ ADDITIONAL FUNCTIONS ------------//

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << this->getName()
			<< " sends a positive high five request to everyone!" << std::endl;
}
