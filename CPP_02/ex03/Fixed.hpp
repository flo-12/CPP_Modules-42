/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:48:04 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:48:05 by fbecht           ###   ########.fr       */
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

	Fixed&	operator=(const Fixed &other);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	bool	operator>(const Fixed &b) const;
	bool	operator<(const Fixed &b) const;
	bool	operator>=(const Fixed &b) const;
	bool	operator<=(const Fixed &b) const;
	bool	operator==(const Fixed &b) const;
	bool	operator!=(const Fixed &b) const;
	Fixed	operator+(const Fixed &b) const;
	Fixed	operator-(const Fixed &b) const;
	Fixed	operator*(const Fixed &b) const;
	Fixed	operator/(const Fixed &b) const;

	static Fixed&		min(Fixed &a, Fixed &b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static Fixed&		max(Fixed &a, Fixed &b);
	static const Fixed&	max(const Fixed &a, const Fixed &b);

	static Fixed		abs(const Fixed &val);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &val);

#endif
