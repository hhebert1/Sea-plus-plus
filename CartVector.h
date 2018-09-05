#ifndef CARTVECTOR_H
#define CARTVECTOR_H

#include <iostream>
using namespace std;
//declare class CartVector

class CartVector
{
public:

	//member variables
	double x;
	double y;

	//member functions
	
	CartVector();
	CartVector(double , double );

};

//Nonmember functions

CartVector operator *(CartVector , double );
CartVector operator /(CartVector , double );
std::ostream& operator << (std::ostream& out, CartVector& p1);

#endif