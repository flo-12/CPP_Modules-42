/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:02:45 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/12 13:02:47 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap( std::string name );
	FragTrap( const FragTrap &other );
	~FragTrap();
	FragTrap&	operator=( const FragTrap &other );

	void	highFivesGuys(void);

	//using			ClapTrap::getAttackDamage;
};



#endif
