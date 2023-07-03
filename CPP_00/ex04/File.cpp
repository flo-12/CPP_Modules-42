
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

void	File::replace(std::string search, std::string rep)
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
				content.insert(pos, rep);
				pos = content.find(search);
			}
			outputFile << content;
			outputFile.close();
		}
		else
			std::cerr << this->_inFile << " is an empty file." << std::endl;
		inputFile.close();
	}
	else
	{
		std::cerr << "Unable to open file " << this->_inFile << "." << std::endl;
		exit(EXIT_FAILURE);
	}
}
