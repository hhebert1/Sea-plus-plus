#include "CoralReef.h"
#include <iostream>
using namespace std;

CoralReef::CoralReef() : GameObject('R', get_id())
{
	state = 'f';
	amount = 100;
	cout << "CoralReef default constructed" << endl;
}

CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject('R', in_id, in_loc)
{
	state = 'f';
	amount = 100;
	cout << "CoralReef constructed" << endl;
}

bool CoralReef::is_empty()
{
	if (amount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int check = 0;

double CoralReef::provide_food(double amount_to_provide)
{
	if (amount >= amount_to_provide)
	{
		if (check == 0)
		{
			amount = amount - amount_to_provide;
			check = check + 1;
		}
		return amount_to_provide;
	}
	else
	{
		double tempamount = amount;
		amount = 0;
		return tempamount;
	}

}

bool CoralReef::update()
{
	if (is_empty() && state!='e')
	{
		state = 'e';
		display_code = 'r';
		cout << "Coral Reef " << get_id() << " has been depleted of food" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void CoralReef::show_status()
{
	cout << "CoralReef Status: ";
	GameObject::show_status();
	cout << " containing food " << amount << endl;
}
