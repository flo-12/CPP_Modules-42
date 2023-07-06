/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:45:44 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/06 11:45:45 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* randomChump:
*	Creates a zombie, names it and the zombie
*	announces himself.
*/
void	randomChump( std::string name )
{
	Zombie	zombie(name);

	zombie.announce();
}
