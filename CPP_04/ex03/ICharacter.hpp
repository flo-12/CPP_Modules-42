/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:20 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:27:22 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const	&getName() const = 0;
	virtual void 				equip( AMateria* m ) = 0;
	virtual void 				unequip( int idx ) = 0;
	virtual void				use( int idx, ICharacter& target ) = 0;
};

#endif
