/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:33 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:57:35 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	cp1("Peer");
	ScavTrap	st1("Evaluator");
	FragTrap	ft1("World");
	DiamondTrap	dt1("Bee");
	DiamondTrap	*dt2 = new DiamondTrap("Dummy");
	delete dt2;

	std::cout << std::endl;

	cp1.setAttackDamage(15);
	dt1.attack(ft1.getName());
	ft1.takeDamage(dt1.FragTrap::getAttackDamage());
	st1.attack(ft1.getName());
	ft1.takeDamage(st1.getAttackDamage());
	
	ft1.beRepaired(10);

	dt1.ScavTrap::setEnergyPoints( 5 );
	for(int i = 0; i < 7; i++)
		dt1.attack( "Dummy" );
	
	dt1.whoAmI();

	std::cout << std::endl;

	return 0;
}
