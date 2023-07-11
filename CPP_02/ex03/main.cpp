/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:47:38 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:47:40 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	csp( Point const a, Point const b, Point const c, Point const point );

int	main()
{
	Point	a( 1, 1 );
	Point	b( 1, 4 );
	Point	c( 4, 1 );
	Point	a1( -1, -1 );
	Point	b1( 0, 0 );
	Point	c1( 2, 2 );
	Point	onLine( 1, 1 );
	Point	isOut1( 0, 0 );
	Point	isOut2( -2.43f, 1.13f );
	Point	isVert1( 1.0f, 1.0f ); 
	Point	isEdge1( 2.0f, 1.0f );
	Point	isEdge2( 3, 2 );
	Point	isIn1( 2, 2 );
	Point	isIn2( 2.54f, 1.43f );

	std::cout << "Created triangle with vertexes "
			<< "A(" << a.getX().toFloat() << "," << a.getY().toFloat() << "), " 
			<< "B(" << b.getX().toFloat() << "," << b.getY().toFloat() << ") and " 
			<< "C(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")"
			<< std::endl;
	
	std::cout << "P(" << isOut1.getX().toFloat() << ","
			<< isOut1.getY().toFloat() << ") is outside the triangle. bsp: "
			<< (csp( a, b, c, isOut1 ) == true ? "Inside" : "Outside" )
			<< std::endl;
	
	std::cout << "P(" << isOut2.getX().toFloat() << ","
			<< isOut2.getY().toFloat() << ") is outside the triangle. bsp: "
			<< (csp( a, b, c, isOut2 ) == true ? "Inside" : "Outside" )
			<< std::endl;

	std::cout << "P(" << isVert1.getX().toFloat() << ","
			<< isVert1.getY().toFloat() << ") is a vertex of the triangle. bsp: "
			<< (csp( a, b, c, isVert1 ) == true ? "Inside" : "Outside" )
			<< std::endl;

	std::cout << "P(" << isEdge1.getX().toFloat() << ","
			<< isEdge1.getY().toFloat() << ") is on the edge of the triangle. bsp: "
			<< (csp( a, b, c, isEdge1 ) == true ? "Inside" : "Outside" )
			<< std::endl;

	std::cout << "P(" << isEdge2.getX().toFloat() << ","
			<< isEdge2.getY().toFloat() << ") is on the edge of the triangle. bsp: "
			<< (csp( a, b, c, isEdge2 ) == true ? "Inside" : "Outside" )
			<< std::endl;
	
	std::cout << "P(" << isIn1.getX().toFloat() << ","
			<< isIn1.getY().toFloat() << ") is inside the triangle. bsp: "
			<< (csp( a, b, c, isIn1 ) == true ? "Inside" : "Outside" )
			<< std::endl;

	
	std::cout << "Created new \"triangle\" (which is a line) with vertexes "
			<< "A(" << a1.getX().toFloat() << "," << a1.getY().toFloat() << "), " 
			<< "B(" << b1.getX().toFloat() << "," << b1.getY().toFloat() << ") and " 
			<< "C(" << c1.getX().toFloat() << "," << c1.getY().toFloat() << ")"
			<< std::endl;

	std::cout << "P(" << onLine.getX().toFloat() << ","
			<< onLine.getY().toFloat() << ") lies on the line of the \"triangle\". bsp: "
			<< (csp( a1, b1, c1, onLine ) == true ? "Inside" : "Outside" )
			<< std::endl;

	return 0;
}
