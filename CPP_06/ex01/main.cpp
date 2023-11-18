/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:38:39 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/12 14:38:40 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
# include "Data.hpp"

void	print_result( Data *before, Data *after )
{
	std::cout << "before: ptr=" << before << " | data=" << before->nbr << " | str=" << before->str << std::endl;
	std::cout << "after:  ptr=" << after << " | data=" << after->nbr << " | str=" << after->str << std::endl;
	std::cout << std::endl;
}

int	main()
{
	Data	*t1 = new Data;
	Data	*t2 = new Data;
	Data	*t3 = new Data;
	Data	*t4 = new Data;
	Data	*t5 = new Data;
	
	t1->nbr = 42;
	t2->nbr = 10;
	t2->str = "Hello World!";
	t3->nbr = 0;
	t4->nbr = 123456789;
	t5->nbr = 1234567890;

	Serializer	s;

	Data	*t11 = s.deserialize( s.serialize( t1 ) );
	Data	*t21 = s.deserialize( s.serialize( t2 ) );
	Data	*t31 = s.deserialize( s.serialize( t3 ) );
	Data	*t41 = s.deserialize( s.serialize( t4 ) );
	Data	*t51 = s.deserialize( s.serialize( t5 ) );

	print_result( t1, t11 );
	print_result( t2, t21 );
	print_result( t3, t31 );
	print_result( t4, t41 );
	print_result( t5, t51 );

	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;

	return 0;
}
