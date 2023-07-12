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

int	main()
{
	ClapTrap	cp1("Peer");
	ClapTrap	cp2("Evaluator");
	ScavTrap	st1("ScavTrap1");
	ScavTrap	st2("ScavTrap2");

	cp1.setAttackDamage(15);
	cp1.attack(cp2.getName());
	cp2.takeDamage(cp1.getAttackDamage());
	st1.attack(cp2.getName());
	cp2.takeDamage(st1.getAttackDamage());
	
	st2.beRepaired(10);

	st2.setEnergyPoints( 5 );
	for(int i = 0; i < 7; i++)
		st2.attack( "Dummy" );
	
	st1.guardGate();

	return 0;
}
