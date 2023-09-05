/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:13 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:27:15 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice( const Ice &other );
	~Ice();
	Ice&	operator=( const Ice &other );

	AMateria*	clone() const;
	void		use( ICharacter& target );
};


#endif
