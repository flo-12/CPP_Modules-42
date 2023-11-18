/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:58:53 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 12:58:55 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>

# define DATABASE "data.csv"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

class BitcoinExchange
{
private:
	BitcoinExchange();

	std::string						_file;
	std::map<std::string, float>	_data;

	void	_readDatabase();
	void	_printResult( std::string date, float value ) const;
	bool	_isValidDate( std::string date ) const;
	bool	_isValidValue( float value ) const;
	bool	_isNumeric( std::string str ) const;
	bool	_printErrorDate( std::string date ) const;

public:
	BitcoinExchange( std::string file );
	~BitcoinExchange();
	BitcoinExchange( BitcoinExchange const & src );
	BitcoinExchange&	operator=( BitcoinExchange const & rhs );

	void	run() const;
};

#endif
