/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:10:05 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:10:08 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
	std::cout << "Destroyed HumanA (" << this->_name << ")" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their \"" << this->_weapon.getType() << "\"" << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}
