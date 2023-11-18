/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    Array.tpp                                          :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2023/09/13 10:44:06 by fbecht            #+#    #+#              */
/*    Updated: 2023/09/13 10:44:09 by fbecht           ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _arr( new T[0] ) {}

template <typename T>
Array<T>::Array( unsigned int const &s ) : _size(s), _arr(new T[s]) {
	for( unsigned int i = 0; i < _size; i++ ) {
		_arr[i] = 0;
	}
}

template <typename T>
Array<T>::Array( Array const &other ) : _size(other._size), _arr(NULL) {
	*this = other;
}

template <typename T>
Array<T>::~Array() {
	if ( _arr )
		delete[] _arr;
	_arr = NULL;
}

template <typename T>
Array<T>&	Array<T>::operator=( Array const &other ) {
	if ( this == &other )
		return *this;
	
	if ( _arr )
		delete[] _arr;
	_size = other._size;
	_arr = new T[_size];
	for ( unsigned int i = 0; i < _size; i++ ) {
		_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[]( unsigned int const &i ) const {
	if ( i >= _size )
		throw IndexAccessException();
	return _arr[i];
}

template <typename T>
unsigned int	Array<T>::size( void ) const {
	return _size;
}

