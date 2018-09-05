#ifndef CAVE_H
#define CAVE_H
#include "GameObject.h"
#include "Fish.h"

class Fish;
 
class Cave : public GameObject
{
private:

	double space;
	char state;

public:

	Cave();
	Cave(int in_id, CartPoint in_loc);
	bool hide_fish(Fish * fish_to_hide);
	bool release_fish(Fish * fish_to_release);
	bool update();
	void show_status();
};

#endif
