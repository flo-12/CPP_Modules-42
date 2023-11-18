/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:38:46 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/13 11:38:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>


template <typename T>
int	easyfind( T &cont, int toFind ) {
	if ( std::find( cont.begin(), cont.end(), toFind ) != cont.end() ) {
		std::cout << "Found it" << std::endl;
		return 0;
	}
	else {
		std::cout << "Not found :-(" << std::endl;
		return -1;
	}
}


#endif
