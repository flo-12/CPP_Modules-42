#include "Fixed.hpp"

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

/* ~Fixed (destructor):
*	Announces itself.
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
Fixed&	Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other)
		return (*this);
	this->_fixedPointNbr = other.getRawBits();
	return (*this);
}
