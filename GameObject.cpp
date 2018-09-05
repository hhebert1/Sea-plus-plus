#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id=0;
	location = CartPoint();
	cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	cout << "GameObject constructed" << endl;
}

CartPoint GameObject::get_location()
{
	return location;
}

int GameObject::get_id()
{
	return id_num;
}

void GameObject::show_status()
{
	cout << display_code << " with ID " << id_num << " at location " << location;
}

void GameObject::drawself(char* grid)
{
	if(grid[0] == '.')
	{
		grid[0] = display_code;
		grid[1] = (char)(get_id() + 48);
	}
	else
	{
		grid[0] = '*';
		grid[1] = ' ';
	}
}
