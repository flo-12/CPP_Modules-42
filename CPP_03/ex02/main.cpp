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

int	main()
{
	ClapTrap	cp1("Peer");
	ScavTrap	st1("Evaluator");
	FragTrap	ft1("World");
	FragTrap	ft2("FragTrap2");
	FragTrap	*ft3 = new FragTrap("Dummy");
	delete ft3;

	std::cout << std::endl;

	cp1.setAttackDamage(15);
	cp1.attack(ft2.getName());
	ft2.takeDamage(cp1.getAttackDamage());
	st1.attack(ft2.getName());
	ft2.takeDamage(st1.getAttackDamage());
	
	ft2.beRepaired(10);

	ft1.setEnergyPoints( 5 );
	for(int i = 0; i < 7; i++)
		ft1.attack( "Dummy" );
	
	st1.guardGate();
	ft1.highFivesGuys();

	std::cout << std::endl;

	return 0;
}
