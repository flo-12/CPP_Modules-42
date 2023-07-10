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
