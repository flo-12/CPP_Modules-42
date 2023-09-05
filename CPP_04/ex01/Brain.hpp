/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:24:47 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:24:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain( const Brain &other );
	~Brain();
	Brain&	operator=( const Brain &other );
};


#endif
