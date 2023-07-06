/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:45:29 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/06 11:45:31 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* newZombie:
*	Creates a zombie, name it and returns it.
*/
Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}
