/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:10:47 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:10:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon		*_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack(void);
};

#endif
