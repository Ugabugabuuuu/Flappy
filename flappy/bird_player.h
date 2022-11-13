#pragma once
class Player
{
protected:
	int y_poz;
	const int x_poz;
	int taskai;
public:
	
	Player() :y_poz(17), x_poz(30), taskai(0) {}
	~Player(){}

	int operator *()
	{
		return taskai;
	}

	void Set_taskai(int t)
	{
		taskai = t;
	}
};
class Bird:Player
{
private:
	char bird[3] = { '^','v','^' };
public:
	void Movement(char input);
	void Bird_placement();
	void Delete_previos_bird_up();
	void Delete_previos_bird_down();
	void No_kb_hit(int go_down);
	bool Collision(int obs_x, int gap);
};
