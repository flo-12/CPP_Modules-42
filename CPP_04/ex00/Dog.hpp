/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:23:36 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:23:39 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
private:
	
public:
	Dog( );
	Dog( const Dog &other );
	~Dog();
	Dog&	operator=( const Dog &other );

	void	makeSound() const;
};





#endif
