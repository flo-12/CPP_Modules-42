/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:57:56 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

ClapTrap::ClapTrap( std::string name ) : 
	_name(name) , _hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "Copy constructor for " << other.getName()
				<< " called" << std::endl;
	
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap &other )
{
	if (this == &other)
		return (*this);
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
	return *this;
}


//------------- SETTER & GETTER FUNCTIONS ------------//

std::string	ClapTrap::getName() const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void	ClapTrap::setName( std::string const name )
{
	if (name.empty())
		_name = name;
}

void	ClapTrap::setHitPoints( unsigned int const points )
{
	_hitPoints = points;
}

void	ClapTrap::setEnergyPoints( unsigned int const points )
{
	_energyPoints = points;
}

void	ClapTrap::setAttackDamage( unsigned int const damage )
{
	_attackDamage = damage;
}


//------------- UTILS FOR PRIVATE ATTR -------------//

/* _decrementEnergyPoints:
*	Checking for overflow when decrementing.
*/
void	ClapTrap::_decrementEnergyPoints( unsigned int amount )
{
	if (amount < _energyPoints)
		_energyPoints -= amount;
	else
		_energyPoints = 0;
}

/* _decrementHitPoints:
*	Checking for overflow when decrementing.
*/
void	ClapTrap::_decrementHitPoints( unsigned int amount )
{
	if (amount < _hitPoints)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
}

/* _incrementHitPoints:
*	Increments hit points.
*/
void	ClapTrap::_incrementHitPoints( unsigned int amount )
{
	_hitPoints += amount;
}


//--------------- ACTIONS TO EXECUTE ---------------//

/* _statusAction:
*	Checks if an action is possible by checking if ClapTrack is
*	dead (_hitPoints <= 0) or has enough energy (_energyPoints <= 0).
*	Prompts a message if action can't be executed.
*	Returns False if action can't be executed and True otherwise.
*/
bool	ClapTrap::_statusAction( std::string action )
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				<< " has no energy Points left and therefore can't do the action "
				<< action << std::endl;
		return false;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				<< " has no hit Points left left and therefore can't do the action "
				<< action << std::endl;
		return false;
	}
	return true;
}

/* attack:
*	Reduce the _energyPoints and prompt the Action.
*	Can only repair itself if _statusAction returns true.
*/
void	ClapTrap::attack( const std::string& target )
{
	if (!this->_statusAction("attack"))
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target 
				<< ", causing " << this->_attackDamage 
				<< " points of damage!" << std::endl;
	
	_decrementEnergyPoints( 1 );
}

/* takeDamage:
*	Decreases the number of _hitPoints by <amount>.
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has " 
				<< this->_hitPoints << " and takes " << amount 
				<< " damage." << std::flush;
	
	_decrementHitPoints( amount );

	std::cout << " It has " << this->_hitPoints << " left!" << std::endl;
}

/* beRepaired:
*	Increases the number of _hitPoints by <amount> and
*	decrements the _energyPoints by one.
*	Can only repair itself if _statusAction returns true.
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_statusAction("repair"))
		return ;
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints 
				<< " Hit points, repairs itself by " << amount 
				<< " points and now has " << std::flush;
	
	_decrementEnergyPoints( 1 );
	_incrementHitPoints( amount );

	std::cout << this->_hitPoints << " Hit points and " 
				<< this->_energyPoints << " energy points are left!"
				<< std::endl;
}
