/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:08:29 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:08:31 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie(void);

	void 	announce(void);
	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
