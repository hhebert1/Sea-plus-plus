#include "Fish.h"
#include <cmath>
#include <iostream>
using namespace std;

bool Fish::update_location()
{
	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
	{
		location = destination;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}
	else
	{
		location = location + delta; 
		if (location.x == destination.x && location.y==destination.y)
		{
			cout << display_code << get_id() << ": I'm there!" << endl;
		}
		else
		{
			cout << display_code << get_id() << ": Just keep swimming..." << endl;
		}
	return false;
	}
}

void Fish::setup_destination(CartPoint dest)
{
	destination = dest;
	delta = (destination - location)*(get_speed() / cart_distance(dest, location));
}

Fish::Fish() : GameObject('F', get_id())
{
	state = 'h';
	energy = 15;
	size = 10;
	home = NULL;
	reef = NULL;
	cout << "Fish default constructed" << endl;
}

Fish::Fish(int in_id, Cave* home) : GameObject('F', in_id, home->get_location())
{
	energy = 15;
	size = 10;
	reef = NULL;
	this->home = home;
	location = home->get_location();
	home->hide_fish(this);
	state = 'h';
	cout << "Fish constructed" << endl;
}

bool Fish::update()
{
	switch (state)
	{
	case 's':
		if (update_location())
		{
			state = 'f';
			return true;
		}
		else
		{
			return false;
		}break;

	case 'e':
	{
		if (size >= 2 * prefeast_size)
		{
			start_hiding(home);
			return true;
		}
		if (reef->is_empty())
		{
			state = 'f';
			cout << display_code << get_id() << ": This reef has no more food for me" << endl;
			return true;
		}
		else
		{
			double amount = reef->provide_food();
			size = size + 0.5*(amount);
			cout << display_code << get_id() << ": Grew to size " << size << endl;
			return false;
		}
	
	}break;

	case 'o':
		
		if (update_location())
		{
			state = 'e';
			cout << display_code << get_id() << ": Starting to dine at a coral reef" << endl;
			prefeast_size = size;
			return true;
		}
		else
		{
			return false;
		}break;

	case 'z':
		if (update_location())
		{
			if (home->hide_fish(this))
			{
				state = 'h';
				cout << display_code << get_id() << ": I am hidden and safe" << endl;
				return true;
			}
			else
			{
				state = 'p';
				cout << display_code << get_id() << ": Help! My home is full" << endl;
				return true;
			}
		return false;
			
		}
		break;

	default:
		return false;

	}
}

double Fish::get_size()
{
	return size;
}

void Fish::start_swimming(CartPoint dest)
{
	if (is_hidden())
	{
		home->release_fish(this);
	}
	setup_destination(dest);
	state = 's';
	cout << "Swimming " << get_id() << " to " << destination << endl;
	cout << display_code << get_id() << ": On my way" << endl;
}

void Fish::start_eating(CoralReef* destReef)
{
	if (is_hidden())
	{
		home->release_fish(this);
	}
	this->reef = destReef;
	setup_destination(reef->get_location());
	state = 'o';
	cout << "Fish " << get_id() << " eating at CoralReef " << reef->get_id() << " and returning back to Cave " << home->get_id() << "." << endl;
	cout << display_code << get_id() << ": Food here I come" << endl;
}

bool Fish::is_hidden()
{
	if (state == 'h')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fish::start_hiding(Cave* destCave)
{
	if (is_hidden())
	{
		home->release_fish(this);
	}
	if (state == 'e')
	{
		cout << display_code << get_id() << ": I'm full. I'm heading home." << endl;
	}
	else
	{
		cout << "Fish " << get_id() << " swimming to Cave " << destCave->get_id() << endl;
		cout << display_code << get_id() << ": Off to saftey" << endl;
	}

	home=destCave;
	setup_destination(destCave->get_location());
	state = 'z';
	
}

void Fish::float_in_place()
{
	if (is_hidden())
	{
		home->release_fish(this);
	}
	state = 'f';
	cout << "Stopping " << get_id() << "." << endl;
	cout << display_code << get_id() << ": Resting my fins." << endl;
}

void Fish::show_status()
{
	cout << "Fish status: ";
	GameObject::show_status();

	switch (state){

	case 'f':
		cout << " is floating. Has a size of: " << size << " and energy of: " << energy << endl; break;

	case 's':
		cout << " has a speed of: " << get_speed() << " and is heading to: " << destination << endl; break;

	case 'o':
		cout << " With a speed of " << get_speed() << endl; break;

	case 'e':
		cout << "is eating at Reef " << reef->get_id() << endl; break;

	case 'z':
		cout << " is swimming to Cave " << home->get_id() << " with a speed of " << get_speed() << endl; break;

	case 'h':
		cout << " is hidden in Cave " << home->get_id() << "." << endl; break;

	case 'p':
		cout << " is panicked!!!! And has a size of " << get_size() << endl; break;
	}
}

double Fish::get_speed()
{
	double speed = (1 / size)*(energy)* 5;
	return speed;
}
