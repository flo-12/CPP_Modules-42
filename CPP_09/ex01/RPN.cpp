/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:16:50 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 17:16:51 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


/**************************************************************/
/*                      CANONICAL FORM                        */
/**************************************************************/

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN( RPN const &src )
{
	*this = src;
}

RPN	&RPN::operator=( RPN const &rhs )
{
	if ( this != &rhs )
		_stack = rhs._stack;

	return *this;
}


/**************************************************************/
/*                         METHODS                            */
/**************************************************************/

int	RPN::eval( std::string expr )
{
	if ( expr.empty() )
		throw std::runtime_error("Error: empty expression");
	
	int	op_count = 0;
	int	nbr_count = 0;
	
	for ( size_t i = 0; i < expr.length(); i++ )
	{
		if ( expr[i] == ' ' )
			continue ;
		else if ( std::isdigit( expr[i] ) 
			&& ( std::isspace( expr[i + 1] ) || expr[i + 1] == '\0' ) )
		{
			nbr_count++;
			_stack.push( expr[i] - '0' );
		}
		else if ( _isValidOperator( expr[i] ) 
			&& ( std::isspace( expr[i + 1] ) || expr[i + 1] == '\0' ) )
		{
			op_count++;
			if ( nbr_count - 1 < op_count )
				throw std::runtime_error("Error: invalid expression");
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			_stack.push( _makeOperation( a, b, expr[i] ) );
		}
		else
			throw std::runtime_error("Error: invalid expression");
	}
	
	if ( nbr_count - 1 != op_count )
		throw std::runtime_error("Error: invalid expression");

	return _stack.top();
}


/**************************************************************/
/*                       PRIVATE METHODS                      */
/**************************************************************/

bool	RPN::_isValidOperator( char c )
{
	if ( c == '+' || c == '-' || c == '*' || c == '/' )
		return true;
	return false;
}

int	RPN::_makeOperation( int a, int b, char op )
{
	switch (op)
	{
		case '+':
			return (b + a);
		case '-':
			return (b - a);
		case '*':
			return (b * a);
		case '/':
			return (b / a);
		default:
			return 0;
	}
}
