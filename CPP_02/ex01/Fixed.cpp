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
	std::cout << "Default constructor called" << std::endl;
}

/* Fixed (copy constructor)
*	Creates s new object f Fixed as a copy of the argument
*	"other".
*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	
	this->_fixedPointNbr = other.getRawBits();
}

/* Fixed (constructor convert int to fixed-point):
*	Takes a constant integer as a parameter and converts it
*	to the corresponding fixed-point value.
*/
Fixed::Fixed( const int val )
{
	std::cout << "Int constructor called" << std::endl;

	this->_fixedPointNbr = val << _nbrFractionalBits;
}

/* Fixed (constructor convert float to fixed-point)
*	Takes a constant floating-point number as a parameter
*	and converts it to the corresponding fixed-point value.
*/
Fixed::Fixed( const float val )
{
	std::cout << "Float constructor called" << std::endl;

	// roundf() or type-casting?
	//this->_fixedPointNbr = static_cast<int>(val * (1 << _nbrFractionalBits));
	this->_fixedPointNbr = roundf(val * (1 << _nbrFractionalBits));
}

/* ~Fixed (destructor):
*	Announces itself.
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	
	return ( this->_fixedPointNbr );
}

/* setRawBits:
*	Sets the raw value of the fixed-point number.
*/
void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_fixedPointNbr = raw;
}

/* copy assignment operator overload:
*	Assigns the values of the argument "other" to the
*	current object.
*/
Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other)
		return (*this);
	this->_fixedPointNbr = other.getRawBits();
	return (*this);
}
