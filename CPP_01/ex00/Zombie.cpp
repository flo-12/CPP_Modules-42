/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:45:20 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/06 11:45:22 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Zombie (constructor):
*/
Zombie::Zombie( std::string name): _name(name)
{

}

/* ~Zombie (destructor):
*	Prints a message with the name of the zombie
*	for debugging purpose.
*/
Zombie::~Zombie()
{
	std::cout << this->_name << ": destroyed" << std::endl;
}

/* announce:
*	Prints out: "<_name>: BraiiiiiiinnnzzzZ..."
*/
void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
