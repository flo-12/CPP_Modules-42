/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 18:19:12 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**************************************************************/
/*                      CANONICAL FORM                        */
/**************************************************************/

PmergeMe::PmergeMe( void ) : _timeVector(0), _timeList(0)
{
}

PmergeMe::~PmergeMe( void )
{
}

PmergeMe::PmergeMe( PmergeMe const &other )
{
	*this = other;
}

PmergeMe&	PmergeMe::operator=( PmergeMe const &other )
{
	if (this == &other)
		return *this;

	this->_vBefore = other._vBefore;
	this->_v = other._v;
	this->_lBefore = other._lBefore;
	this->_l = other._l;
	this->_timeVector = other._timeVector;
	this->_timeList = other._timeList;

	return *this;
}

/**************************************************************/
/*                     PRIVATE METHODS                        */
/**************************************************************/

void	PmergeMe::_initVector( int n, char **argv )
{
	for (int i = 0; i < n; i++)
		this->_v.push_back( std::atoi(argv[i]) );
	this->_vBefore = this->_v;
}

void	PmergeMe::_initList( int n, char **argv )
{
	for (int i = 0; i < n; i++)
		this->_l.push_back( std::atoi(argv[i]) );
	this->_lBefore = this->_l;
}

void	PmergeMe::_mergeSort( std::vector<int> &v )
{
	if (v.size() <= 1)
		return;
	
	std::vector<int>	left;
	std::vector<int>	right;
	size_t				middle = v.size() / 2;
	
	if ( ITERATOR )
	{	
		for ( std::vector<int>::iterator it = v.begin(); it < (v.begin() + middle); it++)
			left.push_back( *it );
		for ( std::vector<int>::iterator it = (v.begin() + middle); it != v.end(); it++ )
			right.push_back( *it );
	}
	else
	{
		for ( size_t i = 0; i < middle; i++ )
			left.push_back( v[i] );
		for ( size_t i = middle; i < v.size(); i++ )
			right.push_back( v[i] );
	}

	_mergeSort( left );
	_mergeSort( right );

	_merge( v, left, right );

}

void	PmergeMe::_mergeSort( std::list<int> &l )
{
	if (l.size() <= 1)
		return;
	
	std::list<int>	left;
	std::list<int>	right;
	size_t			middle = l.size() / 2;
	
	if ( ITERATOR )
	{
		std::list<int>::iterator	itAdvance = l.begin();
		std::advance( itAdvance, middle );

		for ( std::list<int>::iterator it = l.begin(); it != itAdvance; it++)
			left.push_back( *it );
		for ( std::list<int>::iterator it = itAdvance; it != l.end(); it++ )
			right.push_back( *it );
	}
	else
	{
		for ( size_t i = 0; i < middle; i++ )
			left.push_back( l.front() );
		for ( size_t i = middle; i < l.size(); i++ )
			right.push_back( l.front() );
	}
	
	_mergeSort( left );
	_mergeSort( right );
	
	_merge( l, left, right );
}

void	PmergeMe::_merge( std::vector<int> &v, std::vector<int> &left, std::vector<int> &right )
{
	if ( ITERATOR )
	{
		std::vector<int>::iterator	itLeft = left.begin();
		std::vector<int>::iterator	itRight = right.begin();
		std::vector<int>::iterator	it = v.begin();

		while ( itLeft != left.end() && itRight != right.end() )
		{
			if (*itLeft < *itRight)
				*it++ = *itLeft++;
			else
				*it++ = *itRight++;
		}
		while (itLeft != left.end())
			*it++ = *itLeft++;
		while (itRight != right.end())
			*it++ = *itRight++;
	}
	else
	{
		size_t	i = 0;
		size_t	j = 0;
		size_t	k = 0;

		while ( j < left.size() && k < right.size() )
		{
			if ( left[j] < right[k] )
				v[i++] = left[j++];
			else
				v[i++] = right[k++];
		}
		while ( j < left.size() )
			v[i++] = left[j++];
		while ( k < right.size() )
			v[i++] = right[k++];
	}
}

void	PmergeMe::_merge( std::list<int> &l, std::list<int> &left, std::list<int> &right )
{
	std::list<int>::iterator	itLeft = left.begin();
	std::list<int>::iterator	itRight = right.begin();
	std::list<int>::iterator	it = l.begin();

	while ( itLeft != left.end() && itRight != right.end() )
	{
		if ( *itLeft < *itRight )
			*it++ = *itLeft++;
		else
			*it++ = *itRight++;
	}
	while ( itLeft != left.end() )
		*it++ = *itLeft++;
	while ( itRight != right.end() )
		*it++ = *itRight++;
}

void	PmergeMe::_printNbrs( std::vector<int> v, std::string str ) const
{
	std::cout << BOLD << str << ": " << RESET;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::_printNbrs( std::list<int> l, std::string str ) const
{
	std::cout << BOLD << str << ": " << RESET;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool	PmergeMe::_resultsEqual( void ) const
{
	if ( this->_v.size() != this->_l.size() )
		return false;
	
	std::vector<int>::const_iterator	itV = this->_v.begin();
	std::list<int>::const_iterator		itL = this->_l.begin();

	while ( itV != this->_v.end() && itL != this->_l.end() )
	{
		if ( *itV++ != *itL++ )
			return false;
	}
	return true;
}


/**************************************************************/
/*                      PUBLIC METHODS                        */
/**************************************************************/

void	PmergeMe::sortVector( int n, char **argv )
{
	_initVector( n, argv );

	this->_timeVector = static_cast<double>(clock());
	_mergeSort( this->_v );
	this->_timeVector = static_cast<double>(clock()) - this->_timeVector;
}

void	PmergeMe::sortList( int n, char **argv )
{
	_initList( n, argv );

	this->_timeList = static_cast<double>(clock());
	_mergeSort( this->_l );
	this->_timeList = static_cast<double>(clock()) - this->_timeList;
}

void	PmergeMe::printResults( void ) const
{
	if ( !_resultsEqual() )
		std::cout << RED << "Error: Results are not equal." << RESET << std::endl;

	_printNbrs( this->_vBefore, "Before" );
	_printNbrs( this->_v, "After" );
	std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector: " << this->_timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_l.size() << " elements with std::list: " << this->_timeList << " us" << std::endl;
}
