#include <iostream>
#include "CartVector.h"
using namespace std;

//default Constructor
CartVector::CartVector()
{
	x = 0;
	y = 0;
}

//Constructor
CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

//Multiplies a CartVector by a double value
CartVector operator *(CartVector v1, double d)
{
	CartVector v;
	v.x = v1.x*d;
	v.y = v1.y*d;
	return v;
}

//Divides a CartVector by a double value
CartVector operator / (CartVector v1, double d)
{
	CartVector v;
	v.x = v1.x / d;
	v.y = v1.y / d;
	return v;
}

//Prints a CartVector in the form <x,y>
ostream& operator << (ostream& out, CartVector& p1)
{
	out << "<" << p1.x << "," << p1.y << ">";
	return out;
}