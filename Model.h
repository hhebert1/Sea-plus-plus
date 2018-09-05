#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "View.h"

class Fish;


class Model
{
private:
	
	int time;
	GameObject** object_ptrs;
	int num_objects;
	Fish** fish_ptrs;
	int num_fish;
	Cave** cave_ptrs;
	int num_caves;
	CoralReef** reef_ptrs;
	int num_reefs;

public:

	Model();
	~Model();
	Fish* get_Fish_ptr(int id_num);
	CoralReef* get_CoralReef_ptr(int id_num);
	Cave* get_Cave_ptr(int id_num);
	virtual bool update();
	void display(View& view);
	void show_status();
};



#endif
