/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:49 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:51 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_materia[4];

public:
	Character();
	Character( std::string name );
	Character( const Character &other );
	~Character();
	Character&	operator=( const Character &other );

	std::string const	&getName() const;
	void				equip( AMateria* m );
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );
};



#endif
