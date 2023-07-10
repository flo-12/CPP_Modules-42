#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point(/* args */);
	Point(const Point &other);
	Point(const float x, const float y);
	~Point();
	Point&	operator=(const Point &other);

	Fixed	getX() const;
	Fixed	getY() const;
};

#endif