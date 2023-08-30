/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:38:13 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 14:38:15 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string				_name;
public:
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &other );
	~DiamondTrap();
	DiamondTrap&	operator=( const DiamondTrap &other );

	using			ScavTrap::attack;

	void 			whoAmI();
	std::string		diamond_getName() const;
};



#endif
