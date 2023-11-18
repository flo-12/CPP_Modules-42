/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:28 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 10:08:30 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
	void	print( T const &arg ) {
		std::cout << "value=\'" << arg << "\'" << std::endl;
	}

template <typename T>
	void	iter( T *arr, int len, void (*fct)(T const &) ) {
    	for ( int i = 0; i < len; i++ ) {
			fct( arr[i] );
		}
	}

#endif
