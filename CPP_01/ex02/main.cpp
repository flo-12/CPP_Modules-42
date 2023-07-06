/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:42 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:09:44 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string &strREF = str;

	std::cout << "PRINTING MEMORY ADDRESSES:" << std::endl;
	std::cout << "... of the string variable: " << &str << std::endl;
	std::cout << "... held by strPTR: " << strPTR << std::endl;
	std::cout << "... held by strREF: " << &strREF << std::endl;

	std::cout << "PRINTING THE VALUES:" << std::endl;
	std::cout << "... of the string variable: \"" << str << "\"" << std::endl;
	std::cout << "... pointed to by strPTR: \"" << *strPTR << "\"" << std::endl;
	std::cout << "... pointed to by strREF: \"" << strREF << "\"" << std::endl;

	std::cout << std::endl;
	std::string	str2 = "NEW STRING";
	strPTR = &str2;
	strREF = str;

	std::cout << "PRINTING NEW MEMORY ADDRESSES:" << std::endl;
	std::cout << "... of the string variable: " << &str2 << std::endl;
	std::cout << "... held by strPTR: " << strPTR << std::endl;
	std::cout << "... held by strREF: " << &strREF << std::endl;

	std::cout << "PRINTING THE NEW VALUES:" << std::endl;
	std::cout << "... of the string variable: \"" << str2 << "\"" << std::endl;
	std::cout << "... pointed to by strPTR: \"" << *strPTR << "\"" << std::endl;
	std::cout << "... pointed to by strREF: \"" << strREF << "\"" << std::endl;

	return (0);
}
