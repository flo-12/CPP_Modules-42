#include "Fixed.hpp"
#include "Point.hpp"

bool	csp( Point const a, Point const b, Point const c, Point const point );

int	main()
{
	Point	a( 1, 1 );
	Point	b( 1, 4 );
	Point	c( 4, 1 );
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
	
	std::cout << "Is P(" << isOut1.getX().toFloat() << "," << isOut1.getY().toFloat() << ") in the triangle? -> "
			<< (csp( a, b, c, isOut1 ) == true ? "YES" : "NO" )
			<< std::endl;
	
	return 0;
}