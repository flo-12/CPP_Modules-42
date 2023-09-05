/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:26:10 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:26:12 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
private:
	Brain*	_brain;
public:
	Dog( );
	Dog( const Dog &other );
	~Dog();
	Dog&	operator=( const Dog &other );

	void	makeSound() const;
};





#endif
