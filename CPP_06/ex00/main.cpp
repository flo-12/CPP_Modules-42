#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Wrong number of arguments - Please try again" << std::endl;
		return 1;
	}

	ScalarConverter	s;
	s.convert(argv[1]);
	return 0;
}