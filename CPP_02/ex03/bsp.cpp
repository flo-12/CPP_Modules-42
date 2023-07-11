/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:47:22 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:47:25 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* getAreaTriangle:
*	Calculates the area of a triangle defined by the
*	three vertices a, b, c.
*	Returns the area.
*/
Fixed	getAreaTriangle( Point const a, Point const b, Point const c)
{
	return ( Fixed::abs( a.getX() * (b.getY() - c.getY()) 
							+ b.getX() * (c.getY() - a.getY())
							+ c.getX() * (a.getY() - b.getY()) )
							/ Fixed(2) );
}

/* csp:
*	Take three vertices (a, b, c) of a triangle as an argument
*	and checks if the point (argument) is inside the triangle
*	or not.
*	First the area A of the triangle and the areas of the
*	triangles between the point and the vertices (A_1, A_2 and
*	A_3) are calculated.
*		- If the point lies inside the triangle,
*			A_1 + A_2 + A_3 = A
*		- If the point lies on an edge or is a vertex,
*			A_1 = 0 || A_2 = 0 || A_3 = 0
*		- If a, b, c are no triangle (the three points are on
*			a line), A = 0
*	Returns: True if the point is inside the triangle. False
*		otherwise. Thus, if the point is a vertex or on edge,
*		it will return False. It also returns False if a, b, c
*		are not a triangle.
*/
bool	csp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	A = getAreaTriangle(a, b, c);
	Fixed	A_1 = getAreaTriangle(a, b, point);
	Fixed	A_2 = getAreaTriangle(point, b, c);
	Fixed	A_3 = getAreaTriangle(a, point, c);

	if (A == Fixed(0))
		return (false);
	else if (A_1 == Fixed(0) || A_2 == Fixed(0) || A_3 == Fixed(0))
		return (false);
	return ( (A_1 + A_2 + A_3) == A ? true : false );
}
