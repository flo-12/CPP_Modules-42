/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:25:58 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:25:59 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
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

