/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:17:15 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 17:17:18 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>
# include <cctype>


/* RPN class:
*	Is written in the Orthodox Canonical Form.
*	It has the public method eval which takes an inverted Polish mathematical expression as an argument (std::string).
*		- evaluates the expression and displays the result on the standard output.
*		- throws an excpetion if the expression is not valid.
*	An expression is considered as valid if:
*		- all the operands are between 0 and 10
*		- there are as many operators as there are operands minus 1
*	Operations with the following operators are supported: +, -, * and /
*	Brackets are not supported.
*	A std::stack is used to evaluate the expression.
*/
class RPN
{
private:
	std::stack<int>	_stack;

	bool	_isValidOperator( char c );
	int		_makeOperation( int a, int b, char op );

public:
	RPN();
	~RPN();
	RPN(RPN const &src);
	RPN	&operator=(RPN const &rhs);

	int	eval(std::string expr);
	
};


#endif
