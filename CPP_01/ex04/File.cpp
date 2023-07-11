/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:11:19 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:11:21 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filename) : _inFile(filename)
{
	this->_outFile = filename + ".replace";
	return ;
}

File::~File()
{
	return ;
}

void	File::myReplace(std::string search, std::string replace)
{
	std::ifstream   inputFile(this->_inFile.c_str());
	std::string		content;
	size_t			pos;

	if (inputFile.is_open())
	{
		if (std::getline(inputFile, content, '\0'))
		{
			std::ofstream	outputFile(this->_outFile.c_str());
			pos = content.find(search);
			while (pos != std::string::npos)
			{
				content.erase(pos, search.length());
				content.insert(pos, replace);
				pos = content.find(search);
			}
			outputFile << content;
			outputFile.close();
		}
		else
			std::cerr << "\"" << this->_inFile << "\" is an empty file. No *.replace file is created." << std::endl;
		inputFile.close();
	}
	else
	{
		std::cerr << "Unable to open file \"" << this->_inFile << "\"." << std::endl;
		exit(EXIT_FAILURE);
	}
}
