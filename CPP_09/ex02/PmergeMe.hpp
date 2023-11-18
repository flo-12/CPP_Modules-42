/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:17 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/19 18:19:20 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <iterator>

# define ITERATOR true
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define BOLD "\033[1m"

class PmergeMe
{
private:
	std::vector<int>	_vBefore;
	std::vector<int>	_v;
	std::list<int>		_lBefore;
	std::list<int>		_l;
	double				_timeVector;
	double				_timeList;

	void				_initVector( int n, char **argv );
	void				_initList( int n, char **argv );

	void				_mergeSort( std::vector<int> &v );
	void				_mergeSort( std::list<int> &l );
	void				_merge( std::vector<int> &v, std::vector<int> &left, std::vector<int> &right );
	void				_merge( std::list<int> &l, std::list<int> &left, std::list<int> &right );
	
	void				_printNbrs( std::vector<int> v, std::string str ) const;
	void				_printNbrs( std::list<int> l, std::string str ) const;
	
	bool				_resultsEqual() const;

public:
	PmergeMe( void );
	~PmergeMe( void );
	PmergeMe( PmergeMe const &other );
	PmergeMe &operator=( PmergeMe const &other );

	void				sortVector( int n, char **argv );
	void				sortList( int n, char **argv );
	void				printResults( void ) const;
};



#endif
