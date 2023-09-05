/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:01 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:27:04 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure( const Cure &other );
	~Cure();
	Cure&	operator=( const Cure &other );

	AMateria*	clone() const;
	void		use( ICharacter& target );
};


#endif
