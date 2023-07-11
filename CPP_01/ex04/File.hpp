/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:11:30 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/03 15:11:32 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>

class File
{
private:
	std::string	_inFile;
	std::string	_outFile;
public:
	File(std::string filename);
	~File();

	void	myReplace(std::string search, std::string replace);
};


#endif
