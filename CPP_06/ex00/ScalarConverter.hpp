#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>

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

	e_inputType	_findInputType( const std::string str ) const;
	void		_setInputType( const e_inputType type );

public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &other );
	~ScalarConverter();
	ScalarConverter&	operator=( const ScalarConverter &other );

	void	convert( std::string str );
};



#endif