/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:48:12 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 11:48:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->setHitPoints( 100 );
	this->setEnergyPoints( 50 );
	this->setAttackDamage( 20 );

	std::cout << "[ScavTrap] " << this->getName() << " created" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap( other )
{
	std::cout << "[ScavTrap] Copy constructor for " << other.getName()
				<< " called" << std::endl;

	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << this->getName() << " destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap &other )
{
	std::cout << "[ScavTrap] Copy assignment operator for " << other.getName()
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

void	ScavTrap::attack( const std::string& target )
{
	if (!this->_statusAction("attack"))
		return ;
	std::cout << "[ScavTrap] " << this->getName() << " attacks " << target 
				<< ", causing " << this->getAttackDamage() 
				<< " points of damage!" << std::endl;

	_decrementEnergyPoints( 1 );
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << this->getName() << " is now in Gate keeper mode." << std::endl;
}
