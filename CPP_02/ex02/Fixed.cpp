/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:48:23 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:48:24 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* operator<<:
*	ostream operator overload for "std::out << (Fixed)a", which
*	converts (Fixed)a to a float.
*/
std::ostream	&operator<<(std::ostream &out, const Fixed &val)
{
	out << val.toFloat();
	return ( out );
}

/* Fixed (default constructor):
*	Initializes the fixed-point number value to 0
*	and announces itself.
*/
Fixed::Fixed() : _fixedPointNbr( 0 )
{
}

/* Fixed (copy constructor)
*	Creates s new object f Fixed as a copy of the argument
*	"other".
*/
Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointNbr = other.getRawBits();
}

/* Fixed (constructor convert int to fixed-point):
*	Takes a constant integer as a parameter and converts it
*	to the corresponding fixed-point value.
*/
Fixed::Fixed( const int val )
{
	this->_fixedPointNbr = val << _nbrFractionalBits;
}

/* Fixed (constructor convert float to fixed-point)
*	Takes a constant floating-point number as a parameter
*	and converts it to the corresponding fixed-point value.
*/
Fixed::Fixed( const float val )
{
	// roundf() or type-casting?
	//this->_fixedPointNbr = static_cast<int>(val * (1 << _nbrFractionalBits));
	this->_fixedPointNbr = roundf(val * (1 << _nbrFractionalBits));
}

/* ~Fixed (destructor):
*	Announces itself.
*/
Fixed::~Fixed()
{
}

/* toFloat:
*	Converts the fixed-point value to a floating-point value.
*/
float Fixed::toFloat( void ) const
{
	return ( static_cast<float>(this->_fixedPointNbr) / (1 << _nbrFractionalBits) );
}

/* toInt:
*	Converts the fixed-point value to an integer value.
*/
int	Fixed::toInt( void ) const
{
	return ( this->_fixedPointNbr >> _nbrFractionalBits );
}

/* getRawBits:
*	Returns the raw value of the fixed-point value.
*/
int	Fixed::getRawBits( void ) const
{
	return ( this->_fixedPointNbr );
}

/* setRawBits:
*	Sets the raw value of the fixed-point number.
*/
void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointNbr = raw;
}

/* operator=:
*	Copy assignment operator overload. Assigns the values of
*	the argument "other" to the current object.
*/
Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	this->_fixedPointNbr = other.getRawBits();
	return (*this);
}


//--------- INCREMENT & DECREMENT OPERATORS ---------//

/* &operator++:
*	Pre-increment operator. Increments the number by one.
*/
Fixed&	Fixed::operator++()
{
	this->_fixedPointNbr++;
	return (*this);
}

/* operator++:
*	Post-increment operator. Increments the number after
*	the operatorion.
*/
Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();
	return(old);
}

/* &operator++:
*	Pre-decrement operator. Increments the number by one.
*/
Fixed&	Fixed::operator--()
{
	this->_fixedPointNbr--;
	return (*this);
}

/* operator--:
*	Post-decrement operator. Increments the number after
*	the operatorion.
*/
Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	operator--();
	return (old);
}


//--------------- COMPARISON OPERATORS --------------//

/* operator>:
*	Greater-than-operator. Check if the value of "this" is
*	greater than the value of "b".
*/
bool	Fixed::operator>(const Fixed &b) const
{
	return ( this->_fixedPointNbr > b._fixedPointNbr );
}

/* operator<:
*	Less-than-operator. Check if the value of "this" is
*	smaller than the value of "b".
*/
bool	Fixed::operator<(const Fixed &b) const
{
	return ( this->_fixedPointNbr < b._fixedPointNbr );
}

/* operator>=:
*	Greater-than-or-equal-to-operator. Check if the value of "this" is
*	greater or equal than the value of "b".
*/
bool	Fixed::operator>=(const Fixed &b) const
{
	return ( this->_fixedPointNbr >= b._fixedPointNbr );
}

/* operator<=:
*	Less-than-or-equal-to-operator. Check if the value of "this" is
*	smaller or equal than the value of "b".
*/
bool	Fixed::operator<=(const Fixed &b) const
{
	return ( this->_fixedPointNbr <= b._fixedPointNbr );
}

/* operator==:
*	Equal-to-operator. Check if the value of "this" is equal to
*	the value of "b".
*/
bool	Fixed::operator==(const Fixed &b) const
{
	return ( this->_fixedPointNbr == b._fixedPointNbr );
}

/* operator!=:
*	Not-equal-to-operator. Check if the value of "this" is not
*	equal to the value of "b".
*/
bool	Fixed::operator!=(const Fixed &b) const
{
	return ( this->_fixedPointNbr != b._fixedPointNbr );
}


//--------------- ARITHMETIC OPERATORS --------------//

/* operator+:
*	Addition operator. Adds the value of b to this and returns
*	a new element (allocated on stack).
*/
Fixed	Fixed::operator+(const Fixed &b) const
{
	return ( Fixed(this->toFloat() + b.toFloat()) );
}

/* operator-:
*	Subtraction operator. Subtracts the value of b from this
*	and returns a new element (allocated on stack).
*/
Fixed	Fixed::operator-(const Fixed &b) const
{
	return ( Fixed(this->toFloat() - b.toFloat()) );
}

/* operator*:
*	Multiplication operator. Multiplies the values of this
*	and b and returns a new element (allocated on stack).
*/
Fixed	Fixed::operator*(const Fixed &b) const
{
	return ( Fixed(this->toFloat() * b.toFloat()) );
}

/* operator/:
*	Divison operator. Divides the value of this by the
*	value of b and returns a new element (allocated on stack).
*/
Fixed	Fixed::operator/(const Fixed &b) const
{
	return ( Fixed(this->toFloat() / b.toFloat()) );
}


//------------------- MAX and MIN -------------------//

/* min:
*	The function min takes as parameters two references
*	on fixed-point numbers, and returns a reference to
*	the smallest one.
*/
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return ( a < b ? a : b );
}

/* min:
*	The function max takes as parameters two references
*	to constant fixed-point numbers, and returns a
*	reference to the smallest one.
*/
const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return ( a < b ? a : b );
}

/* max:
*	The function max takes as parameters two references
*	on fixed-point numbers, and returns a reference to
*	the greatest one.
*/
Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return ( a > b ? a : b );
}

/* max:
*	The function max takes as parameters two references
*	to constant fixed-point numbers, and returns a
*	reference to the greatest one.
*/
const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return ( a > b ? a : b );
}
