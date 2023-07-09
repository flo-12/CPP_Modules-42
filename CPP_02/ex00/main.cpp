#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << "[MY MESSAGE] setRawBits(4) called and displayed:" << std::endl;
	a.setRawBits(4);
	std::cout << a.getRawBits() << std::endl;
	return 0;
}
