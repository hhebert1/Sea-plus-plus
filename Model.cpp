#include "Model.h"

Model::Model()
{
	time = 0;
	num_objects = 7;
	num_fish = 2;
	num_reefs = 3;
	num_caves = 2;

	object_ptrs = new GameObject*[7];
	fish_ptrs = new Fish*[2];
	reef_ptrs = new CoralReef*[2];
	cave_ptrs = new Cave*[2];

	cave_ptrs[0] = new Cave(1, CartPoint(5, 1));
	cave_ptrs[1] = new Cave(2, CartPoint(6,2));
	fish_ptrs[0] = new Fish(1, cave_ptrs[0]);
	fish_ptrs[1] = new Fish(2, cave_ptrs[1]);
	reef_ptrs[0] = new CoralReef(1, CartPoint(1,20));
	reef_ptrs[1] = new CoralReef(2, CartPoint(20, 1));
	reef_ptrs[2] = new CoralReef(3, CartPoint(20, 20));

	object_ptrs[0] = cave_ptrs[0];
	object_ptrs[1] = cave_ptrs[1];
	object_ptrs[2] = fish_ptrs[0];
	object_ptrs[3] = fish_ptrs[1];
	object_ptrs[4] = reef_ptrs[0];
	object_ptrs[5] = reef_ptrs[1];
	object_ptrs[6] = reef_ptrs[2];

	cout << "Model default constructed" << endl;

}

Model:: ~Model()
{
	for (int i = 0; i < 7; i++)
	{
		delete object_ptrs[i];
	}

	delete[] object_ptrs;

	cout << "Model destructed" << endl;
}

Fish* Model::get_Fish_ptr(int id_num)
{
	for (int i = 0; i < 2; i++)
	{
		if (fish_ptrs[i]->get_id() == id_num)
		{
			return fish_ptrs[i];
		}
	}

	return NULL;
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	for (int i = 0; i < 3; i++)
	{
		if (reef_ptrs[i]->get_id() == id_num)
		{
			return reef_ptrs[i];
		}
	}

	return NULL;
}

Cave* Model::get_Cave_ptr(int id_num)
{
	for (int i = 0; i < 2; i++)
	{
		if (cave_ptrs[i]->get_id() == id_num)
		{
			return cave_ptrs[i];
		}
	}

	return NULL;
}

bool Model::update()
{
	int check = 0;
	time++;

	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->update() == true)
		{
			check = check + 1;
		}
	}

	if (check != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Model::display(View& view)
{
	cout << "Time: " << time << endl;

	view.clear();
	
	for(int i = 0; i < num_objects; i++)
	{
		view.plot(object_ptrs[i]);
	}

	view.draw();

}

void Model::show_status()
{
	for (int i = 0; i < 7; i++)
	{
		object_ptrs[i]->show_status();
	};
}
