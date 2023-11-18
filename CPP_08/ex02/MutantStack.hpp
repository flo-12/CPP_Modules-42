/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:12:18 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/14 17:12:20 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>

template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
private:
	
public:
	MutantStack() {};
	MutantStack( const MutantStack &other ) { *this = other; }
	~MutantStack() {};
	MutantStack&	operator=( const MutantStack &other ) {
		std::stack<T,Container>::operator=(other);
		return *this;
	}

	typedef typename Container::iterator	iterator;

	iterator	begin() { return this->c.begin(); }
    iterator	end() { return this->c.end(); }
};

#endif
