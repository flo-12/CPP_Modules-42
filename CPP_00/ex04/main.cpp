
//#include ".hpp"
#include <iostream>
#include "File.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error usage: <filename> <string_to_find> <string_replace>" << std::endl;
		return (1);
	}
	File	file(argv[1]);
	file.replace(argv[2], argv[3]);
	return (0);
}