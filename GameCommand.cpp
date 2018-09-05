#include "GameCommand.h"

void do_swim_command(Model& model)
{
	int id;
	int x;
	int y;

	cin >> id >> x >> y;
	model.get_Fish_ptr(id)->start_swimming(CartPoint(x,y));
}

void do_go_command(Model& model)
{
	cout << "Advancing one tick" << endl;
	model.update();
	model.show_status();
}

void do_run_command(Model& model)
{
	cout << "Advancing to next event" << endl;
	int i = 0;
	for (int i = 0; i < 5; i++)
	{
		if (model.update())
		{
			break;
		}
	}
	model.show_status();
	
}

void do_eat_command(Model& model)
{
	int id1;
	int id2;
	cin >> id1 >> id2;
	
	model.get_Fish_ptr(id1)->start_eating(model.get_CoralReef_ptr(id2));
}

void do_float_command(Model& model)
{
	int id;
	cin >> id;
	model.get_Fish_ptr(id)->float_in_place();
}

void do_zoom_command(Model& model)
{
	int id1;
	int id2;
	cin >> id1 >> id2;
	model.get_Fish_ptr(id1)->start_hiding(model.get_Cave_ptr(id2));
}
