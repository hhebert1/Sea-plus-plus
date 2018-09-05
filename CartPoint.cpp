#include <math.h>
#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
using namespace std;


//default constructor
CartPoint::CartPoint()
{
	x = 0;
	y = 0;
}

//constructor
CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

//calculates ditance between two CartPoints
double cart_distance(CartPoint p1, CartPoint p2)
{
	double distance = (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);
	distance = sqrt(distance);
	return distance;
}

//Prints CartPoints in form (x,y)
ostream& operator << (ostream& out, CartPoint& p1)
{
	out << "(" << p1.x << "," << p1.y<< ")";
	return out;
}

//Adds a CartVector to a CartPoint
CartPoint operator+ (CartPoint p1, CartVector v1)
{
	CartPoint p;
	p.x = p1.x + v1.x;
	p.y = p1.y + v1.y;
	return p;
}

//Subtracts a CartVector from a CartPoint
CartVector operator- (CartPoint p1, CartPoint p2)
{
	CartVector p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}