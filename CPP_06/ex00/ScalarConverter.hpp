#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <cctype>


enum e_inputType {
	NONE,
	CHAR,
	DOUBLE,
	FLOAT,
	INT,
	LITERAL,
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

	bool		_isChar( const std::string str ) const;
	bool		_isInt( const std::string str ) const;
	bool		_isDouble( const std::string str ) const;
	bool		_isFloat( const std::string str ) const;
	bool		_isLiteral( const std::string str ) const;

	e_inputType	_findInputType( const std::string str ) const;
	void		_setInputType( const e_inputType type );
	
	void		_setValues( const std::string str );

public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &other );
	~ScalarConverter();
	ScalarConverter&	operator=( const ScalarConverter &other );

	void	convert( std::string str );
};



#endif