#include <iostream>
#include <cctype>

std::string	toUpper(const std::string str)
{
	std::string result = str;

	for (std::string::iterator it = result.begin(); it != result.end(); ++it)
		*it = std::toupper(static_cast<unsigned char>(*it));
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		std::cout << toUpper(argv[i]);
	std::cout << std::endl;
	return (0);
}
