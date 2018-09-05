#ifndef CORALREEF_H
#define CORALREEF_H
#include "GameObject.h"

class CoralReef : public GameObject
{
private:

	double amount;
	char state;

public:

	CoralReef();
	CoralReef(int in_id, CartPoint in_loc);

	bool is_empty();
	double provide_food(double amount_to_provide = 20.0);
	bool update();
	void show_status();
};

#endif
