/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:44:00 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 10:44:02 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
	unsigned int	_size;
	T				*_arr;
public:
	Array();
	Array( unsigned int const &s );
	Array( Array const &other );
	~Array();
	Array&	operator=( Array const &other );

	T&	operator[]( unsigned int const &i ) const;
	
	class IndexAccessException : public std::exception {
		virtual const char* what() const throw() {
			return "Array: Couldn't access element in array";
		}
	};

	unsigned int	size( void ) const;
};

# include "Array.tpp"


#endif
