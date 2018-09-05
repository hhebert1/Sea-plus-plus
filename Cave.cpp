#include "Cave.h"
#include <iostream>
using namespace std;

Cave::Cave() : GameObject('c', get_id())
{
	state = 'e';
	space = 100;
	cout << "Cave default constructed" << endl;
}

Cave::Cave(int in_id, CartPoint in_loc) : GameObject('c' , in_id, in_loc)
{
	state = 'e';
	space = 100;
	cout << "Cave constructed" << endl;
}


bool Cave::hide_fish(Fish *fish_to_hide)
{
	if (fish_to_hide->is_hidden() || fish_to_hide->get_size() > space)
	{
		return false;
	}
	else
	{
		space = space - (fish_to_hide->get_size());
		return true;
	}
}

bool Cave::release_fish(Fish *fish_to_release)
{
	if (fish_to_release->is_hidden())
	{
		space = space + (fish_to_release->get_size());
		return true;
	}
	else
	{
		return false;
	}
}

bool Cave::update()
{
	if (space == 0 && state != 'p')
	{
		state = 'p';
		display_code = 'C';
		cout << "Cave" << get_id() << " is packed like sardines" << endl;
		return true;
	}
	else if(space > 0 && state == 'p')
	{
		state = 'e';
		display_code = 'c';
		return true;
	}
	else
	{
		return false;
	}
}

void Cave::show_status()
{
	cout << "Cave Status: ";
	GameObject::show_status();
	 cout << " has a space of " << space << endl;
}
