/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:35 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:37 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal( );
	Animal( const Animal &other );
	virtual ~Animal();
	Animal&	operator=( const Animal &other );

	std::string	getType() const;

	virtual void	makeSound() const;
};


#endif
