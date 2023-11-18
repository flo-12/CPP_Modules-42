/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:20 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:22 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <string>
# include <cctype>


enum e_inputType {
	NONE,
	CHAR,
	DOUBLE,
	FLOAT,
	INT,
	NAN_POS,
	NAN_NEG,
	INF_POS,
	INF_NEG,
	IMPOSSIBLE
} ;


class ScalarConverter
{
private:
	e_inputType	_inputType;
	char		_c;
	double		_d;
	float		_f;
	int			_i;

	void		_setInputType( const std::string str );
	bool		_isChar( const std::string str ) const;
	bool		_isInt( const std::string str ) const;
	bool		_isDouble( const std::string str ) const;
	bool		_isFloat( const std::string str ) const;
	int			_isPseudoLiteral( const std::string str ) const;
	
	void		_setValues( const std::string str );
	void		_printValues();
	void		_printChar();
	void		_printInt();
	void		_printFloat();
	void		_printDouble();

public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &other );
	~ScalarConverter();
	ScalarConverter&	operator=( const ScalarConverter &other );

	void	convert( std::string str );
};



#endif
