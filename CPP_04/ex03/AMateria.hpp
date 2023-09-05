/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:36 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:38 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "Character.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria();
	AMateria( std::string const &type );
	AMateria( const AMateria &other );
	virtual ~AMateria();
	AMateria&	operator=( const AMateria &other );

	std::string const	&getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use( ICharacter& target );
};

#endif
