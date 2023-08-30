/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:38:07 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 14:38:09 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

DiamondTrap::DiamondTrap( std::string name ) : 
	ClapTrap( name ), ScavTrap( name ), FragTrap( name )
{
	std::cout << "[DiamondTrap] " << name << " created" << std::endl;
	
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";

	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) :
	ClapTrap( other ), ScavTrap( other ), FragTrap( other )
{
	std::cout << "[DiamondTrap] Copy constructor for " << other.diamond_getName()
				<< " called" << std::endl;

	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << this->_name << " destroyed" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap &other )
{
	std::cout << "[DiamondTrap] Copy assignment operator for " << other.diamond_getName()
				<< " called" << std::endl;

	if (this == &other)
		return ( *this );
	
	this->_name = other.diamond_getName();
	this->ClapTrap::_name = other.ClapTrap::_name;
	
	this->FragTrap::_hitPoints = other.FragTrap::_hitPoints;
	this->ScavTrap::_energyPoints = other.ScavTrap::_energyPoints;
	this->FragTrap::_attackDamage = other.FragTrap::_attackDamage;

	return ( *this );
}


//------------ ADDITIONAL FUNCTIONS ------------//

/* whoAmI:
*	Displays its name and its ClapTrap name.
*/
void 	DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] My name: " << this->_name
				<< " | my ClapTrap name: " << this->ClapTrap::_name
				<< std::endl;
}

/* diamond_getName:
*	Return _name
*/
std::string	DiamondTrap::diamond_getName() const
{
	return this->_name;
}
