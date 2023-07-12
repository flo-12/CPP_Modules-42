/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:48 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:57:50 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

protected:
	bool	_statusAction( std::string action );
	void	_decrementEnergyPoints( unsigned int amount );
	void	_decrementHitPoints( unsigned int amount );
	void	_incrementHitPoints( unsigned int amount );

public:
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap &other );
	~ClapTrap();
	ClapTrap&	operator=( const ClapTrap &other );

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
	void			setName( std::string const name );
	void			setHitPoints( unsigned int const points );
	void			setEnergyPoints( unsigned int const points );
	void			setAttackDamage( unsigned int const damage );

	void	attack( const std::string& target );
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


/* When ClapTrack attacks, it causes its target to lose
<attack damage> hit points.  */

#endif
