/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:58:47 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 12:58:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/**************************************************************/
/*                      CANONICAL FORM                        */
/**************************************************************/

BitcoinExchange::BitcoinExchange( std::string file ) : _file(file)
{
	this->_readDatabase();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	*this = src;
}

BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this == &rhs )
		return *this;
	
	this->_file = rhs._file;
	this->_data = rhs._data;
	
	return *this;
}

/**************************************************************/
/*                         METHODS                            */
/**************************************************************/

void	BitcoinExchange::run() const
{
	std::ifstream	file( this->_file.c_str() );
	std::string		line;
	std::string		date;
	float			value;

	if (!file.is_open())
	{
		std::cout << RED << "Error: could not open file " << _file << RESET << std::endl;
		exit(1);
	}
	while ( getline( file, line ) )
	{
		date = line.substr( 0, line.find('|') );
		if ( date.length() == 11 && date[10] == ' ' )
			date = date.substr( 0, 10 );
		
		value = std::strtod( line.substr( line.find('|') + 1 ).c_str(), 0 );
		// Check value found
		if ( line.find('|') == std::string::npos )
		{
			std::cout << RED << "Error: bad input, couldn't find value." << RESET << std::endl;
			continue ;
		}
		// Check value is numeric
		if ( !_isNumeric( line.substr( line.find('|') + 1 ) ) )
		{
			std::cout << RED << "Error: bad input, couldn't convert \"" << line.substr( line.find('|') + 1 ) << "\"." << RESET << std::endl;
			continue ;
		}
		this->_printResult( date, value );
	}
	file.close();
}


/**************************************************************/
/*                       PRIVATE METHODS                      */
/**************************************************************/

void	BitcoinExchange::_readDatabase()
{
	std::ifstream	file( DATABASE );
	std::string		line;
	std::string		date;
	float			value;

	if ( !file.is_open() )
	{
		std::cout << RED << "Error: could not open database file " << DATABASE << RESET << std::endl;
		exit(1);
	}
	while ( getline( file, line ) )
	{
		date = line.substr( 0, line.find(',') );
		value = std::strtod( line.substr( line.find(',') + 1 ).c_str(), 0 );
		this->_data[date] = value;
	}
	file.close();
}

void	BitcoinExchange::_printResult( std::string date, float value ) const
{
	std::map<std::string, float>::const_iterator	it;
	float									result;

	if ( !_isValidDate( date ) || !_isValidValue( value ) )
		return ;
	
	it = this->_data.find( date );
	// Date found
	if (it != this->_data.end())
		result = it->second * value;
	// Date not found -> find the closest date (lower bound)
	else
	{
		it = this->_data.lower_bound( date );
		if ( it == this->_data.begin() )
		{
			std::cout << RED << "Error: no data available for " << date << RESET << std::endl;
			return ;
		}
		result = (--it)->second * value;
	}
	std::cout << GREEN << date << " => " << value << " = " << result << RESET << std::endl;
}

bool	BitcoinExchange::_isValidDate( std::string date ) const
{
	int	day;
	int	month;
	int	year;

	// Check the right length of the date
	if ( date.length() != 10 )
		return this->_printErrorDate( date );
	// Check the right format of the date
	if ( date[4] != '-' || date[7] != '-' )
		return this->_printErrorDate( date );

	// Convert the date into int
	year = std::atoi( date.substr( 0, 4 ).c_str() );
	month = std::atoi( date.substr( 5, 2 ).c_str() );
	day = std::atoi( date.substr( 8, 2 ).c_str() );
	
	// Check error of atoi
	if ( year == 0 || month == 0 || day == 0 )
		return this->_printErrorDate( date );
	// Check the right range of the month
	if ( month < 1 || month > 12 )
		return this->_printErrorDate( date );

	// Check the right range of the day for month==February
	if ( month == 2 )
	{
		// if ( leap year )
		if ( year % 4 == 0 )
		{
			if ( day > 29 )
				return this->_printErrorDate( date );
			else
				return true;
		}
		// if ( not leap year )
		else if ( day > 28 )
			return this->_printErrorDate( date );
		else
			return true;
	}
	// Check the right range of the day for month==April, June, September, November (30 days)
	else if ( month == 4 || month == 6 || month == 9 || month == 11 )
	{
		if ( day > 30 )
			return this->_printErrorDate( date );
		else
			return true;
	}
	// Check the right range of the day for month==January, March, May, July, August, October, December (31 days)
	else
	{
		if ( day > 31 )
			return this->_printErrorDate( date );
		else
			return true;
	}
}

bool	BitcoinExchange::_printErrorDate( std::string date ) const
{
	std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
	return false;
}

bool	BitcoinExchange::_isValidValue( float value ) const
{
	if ( value < 0 )
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	else if ( value > 1000 )
	{
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::_isNumeric( std::string str ) const
{
	char*	endptr;
	float	nbr = std::strtod(str.c_str(), &endptr);

	// Check if only spaces are left
    if ( *endptr != '\0' )
	{
		for ( std::string::const_iterator it = str.begin() + (endptr - str.c_str()); *it; it++ ) {
			if ( !std::isspace(*it) )
				return false;
		}
	}

	if ( nbr == 0 && endptr == str.c_str() )
		return false;

	return true;
}
