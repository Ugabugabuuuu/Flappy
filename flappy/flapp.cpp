
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "map.h"
#include <time.h>  
#include <conio.h>
#include "bird_player.h"

using namespace std;

void game_over(Map m, Player p);
void Game(Map m, Bird b);
void Menu();
void I_want_play_more(Map m, Bird b);

int main()
{
	Map m;
	Bird b;
	int input;

	Menu();

	cin >> input;
	system("cls");
	if (input == 1)
	{
		Game(m, b);
	}
	else if (input == 2)
		return 0;
}

void game_over(Map m, Player p)
{
	m.go_to_xy(15, 15);

	char input;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	std::cout << "  __________________________________  " << std::endl;
	m.go_to_xy(15, 16);
	std::cout << "#                                    #" << std::endl;
	m.go_to_xy(15, 17);
	std::cout << "#          Game Over                 #" << std::endl;
	m.go_to_xy(15, 18);
	std::cout << "#                                    #" << std::endl;
	m.go_to_xy(15, 19);
	std::cout << "______________________________________" << std::endl;
	m.go_to_xy(15, 21);
	std::cout << "Points:  " << *p;
}

void Game( Map m, Bird b)
{
	m.Draw_border();

	int count_turns = 0;
	int gap[2];

	gap[0] = m.Gap();
	gap[1] = m.Gap();

	b.Movement(0);

	int go_down = 0;
	bool jump_made = false;
	int k[2] = { 90, 135 };
	Player p;
	int taskai = *p;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int a = 1;

	while (a == 1)
		{
		if (k[0] < 90 && k[0] >= 30)
			{
				if (b.Collision(k[0], gap[0]))
				{

					system("cls");

					game_over(m, p);

					Sleep(5000);
					system("cls");

					I_want_play_more(m, b);

					a = 2;
					break;
				}
			}
			else if (k[1] < 90 && k[1] >= 30)
			{
				if (b.Collision(k[1], gap[1]))
				{

					system("cls");

					m.go_to_xy(15, 15);
					game_over(m,p);

					Sleep(5000);
					system("cls");

					I_want_play_more(m, b);

					a = 2;
					break;
				}
			}
		if (_kbhit())
			b.Movement(_getch());
		else b.No_kb_hit(go_down);
		if (go_down == 2)
			go_down = 0;
		go_down++;
		
		m.Obs(k, gap);
		if (count_turns > 90)
		{
			count_turns = 0;
		}
		if (k[0] < 90 && k[0] >= 30)
		{
			if (b.Collision(k[0], gap[0]))
			{

				system("cls");

				m.go_to_xy(15, 15);
				game_over(m,p);

				Sleep(5000);
				system("cls");

				I_want_play_more(m, b);
				a = 2;
				break;
			}
		}
		else if (k[1] < 90 && k[1] >= 30)
		{
			if (b.Collision(k[1], gap[1]))
			{

				system("cls");

				m.Draw_border();
				game_over(m,p);

				Sleep(5000);
				system("cls");

				I_want_play_more(m, b);

				a = 2;
				break;
			}
		}

		k[0]--;
		k[1]--;

		if (k[0] == 0)
		{
			k[0] = 90;
			gap[0] = m.Gap();
			taskai++;

			p.Set_taskai(taskai);
		}
		if (k[1] == 0)
		{
			taskai++;

			p.Set_taskai(taskai);

			k[1] = 90;
			gap[1] = m.Gap();
		}
		m.go_to_xy(10, 40);

		std::cout << "Taskai:" << *p;
		Sleep(75);
	}
	
}

void Menu()
{
	Map m;
	m.Draw_border();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	m.go_to_xy(20, 12);
	std::cout << (char)219 << (char)219 << "  " << (char)219 << "      " << (char)219 << "    " << (char)219 << (char)219<< "   " << (char)219 << (char)219<<"   " << (char)219 << " " << (char)219;
	m.go_to_xy(20, 13);
	std::cout << (char)219 << "   " << (char)219 << "     " << (char)219 << " " << (char)219 << "   " << (char)219 << " " << (char)219 << "  " << (char)219 << " " << (char)219 << "  " << (char)219<<" "<< (char)219;
	m.go_to_xy(20, 14);
	std::cout << (char)219 << (char)219 << "  " << (char)219 << "     " << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "   " << (char)219 << (char)219 << "    " << (char)219;
	m.go_to_xy(20, 15);
	std::cout << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "  " << (char)219 << "   " << (char)219 << "  " << (char)219 << "    " << (char)219 << "     "<< (char)219;
	m.go_to_xy(17, 18);
	std::cout << "****************************************" << std::endl;
	m.go_to_xy(17, 19);
	std::cout << "*Start game (press 1)                  *" << std::endl;
	m.go_to_xy(17, 20);
	std::cout << "*Exit (press 2)                        *" << std::endl;
	m.go_to_xy(17, 21);
	std::cout << "****************************************" << std::endl;
}

void I_want_play_more(Map m, Bird b)
{
	int input;

	m.go_to_xy(15, 15);

	std::cout << "To restart game press 1" << std::endl;

	m.go_to_xy(15, 16);

	std::cout << " To exit game press 2" << std::endl;
	cin >> input;
	if (input == 1)
	{
		system("cls");
		Game( m,  b);
	}
	else if (input == 2)
	{
		system("cls");
		exit;
	}
}