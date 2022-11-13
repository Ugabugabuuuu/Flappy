#include <iostream>
#include "map.h"
#include <windows.h>
#include <vector>
#include <random>

using namespace std;

int bird_poz = 45;

void Map::Draw_border()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{

			if ((i == 0 || i == y - 1) && j > 0 && j < x - 1)
				map[j][i] = (char)205;
			else if (i == 0 && j == 0)
				map[j][i] = (char)201;
			else if ((j == 0 || j == x - 1) && (i > 0 && i < y - 1))
				map[j][i] = (char)186;
			else if (i == y - 1 && j == 0)
				map[j][i] = (char)200;
			else if (j == x - 1 && i == y - 1)
				map[j][i] = (char)188;
			else if (j == x - 1 && i == 0)
				map[j][i] = (char)187;
			else map[j][i] = (char)32;

			cout << map[j][i];
		}
		cout << endl;
	}
}
void Map::Obs(int obs_poz[], int gap[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	for (int i = 0; i < y; i++)
	{
		for (int h = 0; h < 2; h++)
		{
			if (obs_poz[h] < x - 1)
			{
					if (obs_poz[h]<x-1 && obs_poz[h]>0 && i>0 && i<y-1)
					{
						map[obs_poz[h]][i] = (char)219;

						go_to_xy(obs_poz[h], i);

						cout << map[obs_poz[h]][i];
						if (i<gap[h]+6 && i>gap[h])
						{
							map[obs_poz[h]][i] = (char)32;

							go_to_xy(obs_poz[h], i);

							cout << map[obs_poz[h]][i];
						}
						
					}
					if (map[obs_poz[h]+3][i] == (char)219 && obs_poz[h]>0)
					{
						map[obs_poz[h] + 3][i] = (char)32;

						go_to_xy(obs_poz[h]+3, i);

						cout << map[obs_poz[h] + 3][i];
						//cout << "nooob";
					}

					bool first = map[1][i] == (char)219;
					bool second = map[2][i] == (char)219;
					bool third = map[3][i] == (char)219;

					if (first && second && third)
					{
						map[3][i] = (char)32;

						go_to_xy(3, i);

						cout << map[3][i];
					}
					else if (first && second && !third)
					{
						map[2][i] = (char)32;

						go_to_xy(2, i);

						cout << map[2][i];
					}
					else if (first && !second && !third)
					{
						map[1][i] = (char)32;

						go_to_xy(1, i);

						cout << map[1][i];
					}
			}
			
		}
	
	}
}
void Map::go_to_xy(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;

	CursorPosition.X = x;
	CursorPosition.Y = y;

	SetConsoleCursorPosition(console, CursorPosition);
}
int Map::Gap()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(3, 28);

	return distr(gen);
}