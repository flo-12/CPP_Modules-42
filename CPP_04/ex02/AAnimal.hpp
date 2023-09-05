/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:25:36 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:25:38 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal( );
	AAnimal( const AAnimal &other );
	virtual ~AAnimal();
	AAnimal&	operator=( const AAnimal &other );

	std::string	getType() const;

	virtual void	makeSound() const = 0;
};


#endif
