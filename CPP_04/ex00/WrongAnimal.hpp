/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:23:53 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:23:54 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal( );
	WrongAnimal( const WrongAnimal &other );
	~WrongAnimal();
	WrongAnimal&	operator=( const WrongAnimal &other );

	std::string	getType() const;

	void	makeSound() const;
};


#endif
