/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:39:12 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/14 12:39:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <exception>
# include <vector>

class Span
{
private:
	Span();
	
	unsigned int		_len;
	std::vector<int>	_vec;
public:
	Span( unsigned int N );
	Span( Span const &other );
	~Span();
	Span&	operator=( Span const &other );

	void			addNumber( int nbr );
	void			addNumber( std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd );
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	int	operator[]( unsigned int const i ) const;
	unsigned int	getSize() const;

	class ArrayFull : public std::exception {
		virtual const char* what() const throw() {
			return "Span::addNumber: Vector full";
		}
	};
	class ArraySizeTooSmall : public std::exception {
		virtual const char* what() const throw() {
			return "Span::addNumber: Not enough storage in Vector - nothing is done";
		}
	};
	class MinVectorSize : public std::exception {
		virtual const char* what() const throw() {
			return "Span: Vector size too small to get span";
		}
	};
};




#endif
