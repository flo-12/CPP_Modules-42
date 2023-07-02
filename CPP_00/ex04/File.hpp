
#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>

class File
{
private:
	std::string	_inFile;
	std::string	_outFile;
public:
	File(std::string filename);
	~File();

	void	replace(std::string search, std::string rep);
};


#endif
