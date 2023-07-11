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

int	main()
{
	ClapTrap	cp1("Peer");
	ClapTrap	cp2("Evaluator");
	ClapTrap	cp3(cp1);
	ClapTrap	cp4 = cp2;

	cp3.setName("Peer2");
	cp2.setName("Evaluator2");
	cp1.setAttackDamage(15);
	cp1.attack(cp2.getName());
	cp2.takeDamage(cp1.getAttackDamage());
	cp4.setAttackDamage(10);
	cp4.attack(cp1.getName());
	cp1.takeDamage(cp4.getAttackDamage());	// cp1 dead
	
	cp1.beRepaired(10);	// shouldn't work, because dead
	cp3.beRepaired(10);

	for(int i = 0; i < 12; i++)
		cp3.attack( "Dummy" );

	return 0;
}
