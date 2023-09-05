/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:25:00 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:25:02 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain*	_brain;
public:
	Cat();
	Cat( const Cat &other );
	~Cat();
	Cat&	operator=( const Cat &other );

	void	makeSound() const;
};


#endif

