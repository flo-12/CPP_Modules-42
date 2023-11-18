/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:15 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:17 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

ScalarConverter::ScalarConverter()
	: _inputType( NONE )
{
}

ScalarConverter::ScalarConverter( const ScalarConverter &other )
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter &other )
{
	if ( this == &other)
		return *this;

	_inputType = other._inputType;
	_c = other._c;
	_d = other._d;
	_f = other._f;
	_i = other._i;
	return *this;
}


//--------------- PUBLIC MEMBER FUNCTIONS ---------------//

void	ScalarConverter::convert( std::string str )
{
	_setInputType( str );

	if ( _inputType == IMPOSSIBLE )
	{
		std::cout << "Conversion due to bad input not possible" << std::endl;
        return ;
	}

	_setValues( str );
	_printValues();
}


//--------------- FIND INPUT TYPE ---------------//

void	ScalarConverter::_setInputType( const std::string str )
{
	if ( _isChar( str ) )
		_inputType = CHAR;
	else if ( _isInt( str ) )
		_inputType = INT;
	else if ( _isDouble( str ) )
		_inputType = DOUBLE;
	else if ( _isFloat( str ) )
		_inputType = FLOAT;
	else if ( _isPseudoLiteral( str ) >= 0 )
		_inputType = (e_inputType)(_isPseudoLiteral( str ) + NAN_POS);
	else
		_inputType = IMPOSSIBLE;
}

bool	ScalarConverter::_isChar( const std::string str ) const
{
	return str.length() == 1 && !std::isdigit( str[0] );
}

bool	ScalarConverter::_isInt( const std::string str ) const
{
	int	sign = 0;

	if ( str[0] == '-' || str[0] == '+' )
		sign = 1;
	for (std::string::const_iterator it = ( str.begin() + sign ); it <= str.end(); it++) {
		if ( !( *it >= '0' && *it <= '9' ) )
			return false;			
	}
	return true;
}

bool	ScalarConverter::_isDouble( const std::string str ) const
{
	bool	decP = false;
	int		sign = 0;

	if ( str[0] == '-' || str[0] == '+' )
		sign = 1;
	for (std::string::const_iterator it = ( str.begin() + sign ); it != str.end(); ++it) {
		if ( *it == '.' && !decP )
			decP = true;
		else if ( !std::isdigit( *it ) )
			return false;
	}
	return true;
}

bool	ScalarConverter::_isFloat( const std::string str ) const
{
	if ( str.length() <= 1 )
		return false;
	
	bool	decP = false;
	int		sign = 0;

	if ( str[0] == '-' || str[0] == '+' )
		sign = 1;
	for (std::string::const_iterator it = ( str.begin() + sign ); it != str.end() - 1; ++it) {
		if ( *it == '.' && !decP )
			decP = true;
		else if ( !std::isdigit( *it ) )
			return false;
	}
	if ( *(str.end() - 1) == 'f' )
		return true;
	else
		return false;
}

int	ScalarConverter::_isPseudoLiteral( const std::string str ) const
{
	if ( str == "nan" || str == "nanf" || str == "+nan" || str == "+nanf" )
		return 0;
	else if ( str == "-nan" || str == "-nanf" )
		return 1;
	else if ( str == "inf" || str == "+inf" || str == "inff" || str == "+inff" )
		return 2;
	else if ( str == "-inf" || str == "-inff" )
		return 3;
	return -1;
}


//--------------- SET VALUES ---------------//

void	ScalarConverter::_setValues( const std::string str )
{
	if ( _inputType == CHAR)
	{
		_c = str[0];
		_i = static_cast< int >( _c );
		_f = static_cast< float >( _c );
		_d = static_cast< double >( _c );
	
	}
	else if ( _inputType == DOUBLE || _inputType == FLOAT || _inputType == INT )
	{
		_d = std::strtod( str.data(), 0 );
		_i = static_cast< int >( _d );
		_f = static_cast< float >( _d );
		_c = static_cast< char >( _d );
	
	}
}


//------------- PRINT VALUES -------------//

void	ScalarConverter::_printValues()
{
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}

void	ScalarConverter::_printChar()
{
	std::cout << "char: ";
	if ( _inputType >= NAN_POS && _inputType <= INF_NEG )
		std::cout << "impossible" << std::endl;
	else if ( _d > 0 && static_cast< double >( _c ) != floorf( _d ) )
		std::cout << "Out of range" << std::endl;
	else if ( _d < 0 && static_cast< double >( _c ) != ceilf( _d ) )
		std::cout << "Out of range" << std::endl;
	else if ( !std::isprint( _c ) )
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << _c << "\'" << std::endl;
}

void	ScalarConverter::_printInt()
{
	std::cout << "int: ";
	if ( _inputType >= NAN_POS && _inputType <= INF_NEG )
		std::cout << "impossible" << std::endl;
	else if ( _d > 0 && static_cast< double >( _i ) != floorf( _d ))
		std::cout << "Out of range" << std::endl;
	else if ( _d < 0 && static_cast< double >( _i ) != ceilf( _d ))
		std::cout << "Out of range" << std::endl;
	else
		std::cout << _i << std::endl;
}

void	ScalarConverter::_printFloat()
{
	std::cout << "float: ";
	if ( _inputType == NAN_POS )
		std::cout << "nanf" << std::endl;
	else if ( _inputType == NAN_NEG )
		std::cout << "-nanf" << std::endl;
	else if ( _inputType == INF_POS )
		std::cout << "inff" << std::endl;
	else if ( _inputType == INF_NEG )
		std::cout << "-inff" << std::endl;
	else if ( std::isinf( _f ))
		std::cout << "Out of range - Input too low/high" << std::endl;
	else
		std::cout << _f << "f" << std::endl;
}

void	ScalarConverter::_printDouble()
{
	std::cout << "double: ";
	if ( _inputType == NAN_POS )
		std::cout << "nan" << std::endl;
	else if ( _inputType == NAN_NEG )
		std::cout << "-nan" << std::endl;
	else if ( _inputType == INF_POS )
		std::cout << "inf" << std::endl;
	else if ( _inputType == INF_NEG )
		std::cout << "-inf" << std::endl;
	else if ( std::isinf( _d ))
		std::cout << "Out of range - Input too low/high" << std::endl;
	else
		std::cout << _d << std::endl;
}
