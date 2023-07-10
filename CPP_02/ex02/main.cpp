#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c( -5.4f );
	Fixed		d( -5.4f );
	Fixed		e( 2 );
	
	std::cout << std::endl << "START TESTS:" << std::endl << std::endl;

	std::cout << "a (initialized with 0) = " << a << std::endl;
	std::cout << "increment a++ -> a = " << ++a << std::endl;
	std::cout << "increment a++ -> a = " << ++a << std::endl;
	std::cout << "b (initialized with 10.1) = " << b << std::endl;
	
	std::cout << "b(10.1) > c(-5.4) ? -> " << ( b > c ) << std::endl;
	std::cout << "b(10.1) < c(-5.4) ? -> " << ( b < c ) << std::endl;
	std::cout << "c(-5.4) >= d(-5.4) ? -> " << ( c >= d ) << std::endl;
	std::cout << "a(0.039) <= d(-5.4) ? -> " << ( a <= d ) << std::endl;
	std::cout << "c(-5.4) == d(-5.4) ? -> " << ( c == d ) << std::endl;
	std::cout << "b(10.1) == c(-5.4) ? -> " << ( b == c ) << std::endl;
	std::cout << "c(-5.4) != d(-5.4) ? -> " << ( c != d ) << std::endl;
	std::cout << "b(10.1) != c(-5.4) ? -> " << ( b != c ) << std::endl;

	std::cout << "b(10.1) + c(-5.4) = " << ( b + c ) << std::endl;
	std::cout << "a(0.0039) - a(0.0039) = " << ( a - a ) << std::endl;
	std::cout << "e(2) * b(10.1) = " << ( e * b ) << std::endl;
	std::cout << "c(-5.4) / e(2) = " << ( c / e ) << std::endl;

	std::cout << "max of a(0.0039) and b(10.1) -> " << Fixed::max( a, b ) << std::endl;
	std::cout << "max of b(10.1) and b(10.1) -> " << Fixed::max( a, b ) << std::endl;
	std::cout << "min of e(2) and d(-5.4) -> " << Fixed::min( e, d ) << std::endl;
	std::cout << "min of d(-5.4) and e(2) -> " << Fixed::min( d, e ) << std::endl;

	return 0;
}