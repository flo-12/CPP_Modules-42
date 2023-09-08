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


//------------- GET- & SET-FUNCTIONS -------------//

//--------------- MEMBER FUNCTIONS ---------------//

bool	ScalarConverter::_isChar( const std::string str ) const
{
	return str.length() == 1 && std::isprint( str[0] ) && std::isdigit( str[0] );
}

bool	ScalarConverter::_isInt( const std::string str ) const
{
	int	sign = 0;

	if ( str[0] == '-' || str[0] == '+' )
		sign = 1;
	for (std::string::const_iterator it = ( str.begin() + sign ); it != str.end(); ++it) {
		if ( !std::isdigit( *it ) )
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

}

bool	ScalarConverter::_isLiteral( const std::string str ) const
{

}


e_inputType	ScalarConverter::_findInputType( const std::string str ) const
{
	if ( _isChar( str ) )
		return CHAR;
	else if ( _isInt( str ) )
		return INT;
	else if ( _isDouble( str ) )
		return DOUBLE;
	else if ( _isFloat( str ) )
		return FLOAT;
	else if ( _isLiteral( str ) )
		return LITERAL;
	else
		return IMPOSSIBLE;

}

void	ScalarConverter::_setInputType( const e_inputType type )
{

}

void	ScalarConverter::_setValues( const std::string str )
{
	switch ( _inputType ) {
	case CHAR:
		_c = str[0];
		_i = static_cast< int >( _c );
		_f = static_cast< float >( _c );
		_d = static_cast< double >( _c );
		break;
	case DOUBLE:
		_d = std::atof( str.data() );
		_i = static_cast< int >( _d );
		_f = static_cast< float >( _d );
		_c = static_cast< char >( _d );
		break;
	case FLOAT:
		_f = std::stof( str );
		_i = static_cast< int >( _f );
		_d = static_cast< double >( _f );
		_c = static_cast< char >( _f );
		break;
	case INT:
		_i = std::stoi( str );
		_f = static_cast< float >( _i );
		_d = static_cast< double >( _i );
		_c = static_cast< char >( _i );
		break;
	case LITERAL:
		std::cout << "WHAT TO DO HERE????" << std::endl;
		break;
	default:
		break;
    }
}

void	ScalarConverter::convert( std::string str )
{
	_setInputType( _findInputType( str ) );

	if ( _inputType == IMPOSSIBLE )
	{
		std::cout << "Conversion due to bad input not possible" << std::endl;
        return ;
	}

	_setValues( str );

}
