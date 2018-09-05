#ifndef CARTPOINT_H
#define CARTPOINT_H
#include "CartVector.h"

//declare class CartPoint

class CartPoint
{
public:

	//member variables

	double x;
	double y;

	//member functions

	CartPoint();
	CartPoint(double x, double y);

};

//Nonmember functions

double cart_distance(CartPoint, CartPoint);
std::ostream & operator<<(std::ostream & out, CartPoint & point);
CartPoint operator+ (CartPoint p1, CartVector v1);
CartVector operator- (CartPoint p1, CartPoint p2);


#endif