/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:51 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:53 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cmath>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:

public:
	Serializer();
	Serializer( const Serializer &other );
	~Serializer();
	Serializer&	operator=( const Serializer &other );

	uintptr_t	serialize( Data* ptr );
	Data*		deserialize( uintptr_t raw );

};


#endif
