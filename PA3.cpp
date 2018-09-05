#include <iostream>
#include "GameCommand.h"
using namespace std;

int main()
{
	Model *model = new Model();
	View *view = new View();

	model->show_status();

	char command;
	
	do{
		model->display(*view);
		cout << "Enter command: ";
		cin >> command;

		switch (command)
		{
		case 's':
			do_swim_command(*model); break;
		case 'e':
			do_eat_command(*model); break;
		case 'f':
			do_float_command(*model); break;
		case 'z':
			do_zoom_command(*model); break;
		case 'g':
			do_go_command(*model); break;
		case 'r':
			do_run_command(*model); break;
		case 'q':
			cout << "Terminating Program" << endl;
			break;
		}
	} while (command != 'q');
	

	delete model;

	return 0;
}
