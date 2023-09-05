/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:13 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
private:
	
public:
	WrongDog( );
	WrongDog( const WrongDog &other );
	~WrongDog();
	WrongDog&	operator=( const WrongDog &other );

	void	makeSound() const;
};


#endif
