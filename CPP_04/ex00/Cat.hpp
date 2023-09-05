/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:23:09 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:23:11 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
private:
	
public:
	Cat( );
	Cat( const Cat &other );
	~Cat();
	Cat&	operator=( const Cat &other );

	void	makeSound() const;
};


#endif

