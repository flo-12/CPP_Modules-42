/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:40:07 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:40:09 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>


template <typename T>
	void	swap(T &arg1, T &arg2) {
    	T	tmp = arg2;
		arg2 = arg1;
		arg1 = tmp;
	}

template <typename T>
	T	min(T const &arg1, T const &arg2) {
    	if ( arg1 < arg2 )
			return arg1;
		else
			return arg2;
	}

template <typename T>
	T	max(T const &arg1, T const &arg2) {
    	if ( arg1 > arg2 )
			return arg1;
		else
			return arg2;
	}


#endif
