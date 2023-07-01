
# include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string &strREF = str;

	std::cout << "memory address of the string variable: " << &str << std::endl;
	std::cout << "memory address held by strPTR: " << strPTR << std::endl;
	std::cout << "memory address held by strREF: " << &strREF << std::endl;

	std::cout << "value of the string variable: " << str << std::endl;
	std::cout << "value ointed to by strPTR: " << *strPTR << std::endl;
	std::cout << "value ointed to by strREF: " << strREF << std::endl;

	return (0);
}