#include <iostream>
#include "map.h"
#include "bird_player.h"
#include <windows.h>

Map mp;

void Bird::Movement(char input)
{
	if (input == (char)32)
	{
		if (y_poz > 1)
			y_poz--;
		else No_kb_hit(2);
		
		Delete_previos_bird_down(); 

		mp.go_to_xy(x_poz, y_poz);
		Bird_placement();
	}
}
void Bird::Bird_placement()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	mp.go_to_xy(x_poz, y_poz);

	mp.map[x_poz][y_poz] = bird[0];
	mp.map[x_poz+1][y_poz] = bird[1];
	mp.map[x_poz+2][y_poz] = bird[2];

	std::cout << mp.map[x_poz][y_poz] << mp.map[x_poz + 1][y_poz] << mp.map[x_poz + 2][y_poz];

}
void Bird::No_kb_hit(int go_down)
{
	if(y_poz <= mp.y - 3 && go_down == 2)
		y_poz++; 
	if (mp.y < y_poz)
		y_poz--;

	Delete_previos_bird_up();

	mp.go_to_xy(x_poz, y_poz);

	Bird_placement();
}
void Bird::Delete_previos_bird_up()
{
	if (y_poz > 1)
	{
		if (mp.map[x_poz][y_poz - 1] != (char)219)
		{
			mp.go_to_xy(x_poz, y_poz - 1);

			mp.map[x_poz][y_poz - 1] = (char)32;
			std::cout << (char)32;
		}


		if (mp.map[x_poz][y_poz - 1] != (char)219)
		{
			mp.map[x_poz + 1][y_poz - 1] = (char)32;
			std::cout << (char)32;
		}

		if (mp.map[x_poz][y_poz - 1] != (char)219)
		{
			mp.map[x_poz + 2][y_poz - 1] = (char)32;
			std::cout << (char)32;
		}
	}
}
void Bird::Delete_previos_bird_down()
{
	if (y_poz < mp.y - 2)
		{
			if (mp.map[x_poz][y_poz - 1] != (char)219)
				{
					mp.go_to_xy(x_poz, y_poz + 1);

					mp.map[x_poz][y_poz +1] = (char)32;
					std::cout << (char)32;
				}

				if (mp.map[x_poz][y_poz - 1] != (char)219)
				{
					mp.map[x_poz+1][y_poz + 1] = (char)32;
					std::cout << (char)32;
				}
		

				if (mp.map[x_poz][y_poz - 1] != (char)219)
				{
					mp.map[x_poz+2][y_poz + 1] = (char)32;
					std::cout << (char)32;
				}
		}	
}
bool Bird::Collision(int obs_x, int gap)
{
		if (((x_poz + 2 == obs_x || x_poz + 1 == obs_x || x_poz == obs_x) && (y_poz < gap || y_poz > gap + 4)) ||
		((x_poz + 2 >= obs_x && (x_poz <= obs_x)) &&
			(y_poz < gap || y_poz > gap + 4)))
		return true;
	else return false;
}