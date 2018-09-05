#ifndef FISH_H
#define FISH_H

#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"

class Cave;

class Fish : public GameObject
{
private:

	double energy;
	double size;
	double prefeast_size;
	CartPoint destination;
	CartVector delta;
	CoralReef* reef;
	Cave *home;
	bool update_location();
	void setup_destination(CartPoint dest);
	char state;

public:

	Fish();
	Fish(int in_id, Cave *home);

	bool update();
	double get_size();
	void start_swimming(CartPoint dest);
	void start_eating(CoralReef* destReef);
	bool is_hidden();
	void start_hiding(Cave* destCave);
	void float_in_place();
	void show_status();
	double get_speed();

};

#endif
