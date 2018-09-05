#include "View.h"

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
	ix = ((location.x - origin.x) / scale);
	iy = ((location.y - origin.y) / scale);

	if ((0 <= ix && ix <= size) && (0 <= iy && iy <= size))
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display" << endl;
		return false;
	}
}

View::View()
{
	size = 11;
	scale = 2;
	origin = CartPoint();
}

void View::clear()
{
	for (int i = 0; i < view_maxsize; i++)
	{
		for (int j = 0; j < view_maxsize; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}
void View::plot(GameObject* ptr)
{
	int x, y;
	if(get_subscripts(x, y, ptr->get_location()))
	{
		ptr->drawself(grid[x][y]);
	}
}
void View::draw()
{
	
	for (int i = size - 1; i >= 0; i--)
	{
		if(i % (int)scale == 0)
		{
			cout << i*scale;
			if(i*scale < 10)
			{
				cout << " ";
			}
		}
		else
		{
			cout << "  ";
		}

		for(int j = 0; j < size; j++)
		{
			cout << grid[j][i][0] << grid[j][i][1];
		}
		cout << endl;
	}
	cout << "  ";
	for (int j = 0; j <= size; j++)
	{
		if(j % (int)scale == 0)
		{
			cout << j*scale;
			if(j*scale < 10)
			{
				cout << " ";
			}
		}
		else
		{
			cout << "  ";
		}
	}
	cout << endl;
}
