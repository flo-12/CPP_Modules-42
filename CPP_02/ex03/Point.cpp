/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:47:46 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/11 17:47:48 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Point (default constructor):
*	Set _x and _y by default to 0.
*/
Point::Point() : _x(0) , _y(0)
{
}

/* Point (copy constructor):
*	Copies other to current element.
*/
Point::Point(const Point &other) : _x(other._x) , _y(other._y)
{
}

/* Point (set-initialize constructor):
*	Initializes _x and _y with the parameters.
*/
Point::Point(const float x, const float y) : _x(x) , _y(y)
{
}

/* ~Point (default destructor)
*	
*/
Point::~Point()
{
}

/* operator=:
*	Copy-assignment-operator.
*/
Point&	Point::operator=(const Point &other)
{
	if (this == &other)
		return (*this);
	( Fixed ) this->_x = other.getX();
	( Fixed ) this->_y = other.getY();
	return (*this);
}

/* getX:
*	Returns attribute _x.
*/
Fixed	Point::getX() const
{
	return ( this->_x );
}

/* getY:
*	Returns attribute _y.
*/
Fixed	Point::getY() const
{
	return ( this->_y );
}
