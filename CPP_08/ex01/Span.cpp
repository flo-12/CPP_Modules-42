/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:39:18 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/14 12:39:20 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


//------------ ORTHODOX CANONICAL FORM ------------//

Span::Span( unsigned int N ) : _len( N )
{
}

Span::Span( Span const &other ) : _len(other._len), _vec(other._vec)
{}

Span::~Span()
{
}

Span&	Span::operator=( Span const &other )
{
	if( this == &other )
		return *this;

	_len = other._len;
	_vec = other._vec;
	return *this;
}


//--------------- MEMBER FUNCTIONS ---------------//

void	Span::addNumber( int nbr )
{
	if( _vec.size() >= _len )
		throw Span::ArrayFull();

	_vec.push_back( nbr );
}

void	Span::addNumber( std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd )
{
	if ( _vec.size() + std::distance( itBegin, itEnd ) > _len )
		throw Span::ArraySizeTooSmall();

	_vec.insert( _vec.end(), itBegin, itEnd );
}

unsigned int	Span::shortestSpan() const
{
	if ( _vec.size() < 2 )
		throw Span::MinVectorSize();

	long long	shortSpan = std::abs(static_cast<long long>(_vec[0]) - static_cast<long long>(_vec[1]));
	for ( std::vector<int>::const_iterator it1 = _vec.begin(); it1 != _vec.end(); it1++ ) {
		for ( std::vector<int>::const_iterator it2 = it1 + 1; it2 != _vec.end(); it2++ ) {
			if ( std::abs(static_cast<long long>(*it1) - static_cast<long long>(*it2)) 
					< shortSpan )
				shortSpan = std::abs(static_cast<long long>(*it1) - static_cast<long long>(*it2));
		}
	}

	return static_cast<unsigned int>( shortSpan );
}

unsigned int	Span::longestSpan() const
{
	if ( _vec.size() < 2 )
		throw Span::MinVectorSize();
	
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

int	Span::operator[]( unsigned int const i ) const
{
	return _vec[i];
}

unsigned int	Span::getSize() const
{
	return _vec.size();
}
