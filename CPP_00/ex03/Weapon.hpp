/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:10:39 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:10:41 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string	&getType(void);
	void				setType(std::string type);
};

#endif
