/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:48:07 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 11:48:09 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
	/* data */
public:
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap &other );
	~ScavTrap();
	ScavTrap&	operator=( const ScavTrap &other );

	void	guardGate();
	void	attack( const std::string& target );
};


#endif
