#include "ScalarConverter.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter &other )
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter &other )
{
	*this = other;
	return *this;
}


//------------- GET- & SET-FUNCTIONS -------------//

//--------------- MEMBER FUNCTIONS ---------------//

void	ScalarConverter::convert( std::string str )
{
	char*	end[15];
    std::cout << "Parsing \"" << str << "\":" << std::endl;
    double f = std::strtod(str.c_str(), end);
	std::cout << f << std::endl;

	double	storeNb = std::atof(str.data());
	std::cout << "with atof: " << storeNb << std::endl;


	_setInputType( _findInputType( str ) );


	if ( _inputType == IMPOSSIBLE )
	{
		std::cout << "Conversion due to bad input not possible" << std::endl;
        return ;
	}
    /* switch ( _type ) {
    case CHAR:
        _c = _str[0];
        _n = static_cast< int >( _c );
        _f = static_cast< float >( _c );
        _d = static_cast< double >( _c );
        break;
    case INT:
        _n = std::stoi( _str );
        _f = static_cast< float >( _n );
        _d = static_cast< double >( _n );
        _c = static_cast< char >( _n );
        break;
    case FLOAT:
        _f = std::stof( _str );
        _n = static_cast< int >( _f );
        _d = static_cast< double >( _f );
        _c = static_cast< char >( _f );
        break;
    case DOUBLE: */
        _d = std::atof( str.data() );
        _i = static_cast< int >( _d );
        _f = static_cast< float >( _d );
        _c = static_cast< char >( _d );
		std::cout << "_d=" << _d << " | _i=" << _i << " | _f=" << _f << " | _c=" << _c << std::endl;
    /*     break;
    default:
        break;
    } */

}
