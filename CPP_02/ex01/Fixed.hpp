/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:48:52 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:48:53 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_fixedPointNbr;
	static const int	_nbrFractionalBits = 8;
public:
	Fixed();
	Fixed( const Fixed &other );
	Fixed( const int val );
	Fixed( const float val );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	Fixed	&operator=(const Fixed &other);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &val);

#endif
