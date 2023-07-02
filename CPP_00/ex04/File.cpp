
#include "File.hpp"

File::File(std::string filename)
{
	this->_inFile = filename;
	this->_outFile = filename + ".replace";
	return ;
}

File::~File()
{
	return ;
}

void	File::replace(std::string search, std::string rep)
{
	std::ifstream   ifs(this->_inFile);
	std::string		content;
	int				pos;

	if (ifs.is_open())
	{
		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream	ofs(this->_outFile);
			pos = content.find(search);
			while (pos != std::string::npos)
			{
				content.erase(pos, search.length());
				content.insert(pos, rep);
				pos = content.find(search);
			}
			ofs << content;
			ofs.close
		}
		else
			std::cerr << this->_inFile << " is an empty file." << std::endl;
		ifs.close;
	}
	else
	{
		std::cerr << "Unable to open file " << this->_inFile << "." << std::endl;
		exit(EXIT_FAILUE);
	}
}
