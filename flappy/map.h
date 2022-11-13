class Map
{
private:
	int ob_width;
public:
	char map[90][35];
	int x, y;

	Map(): x(90), y(35), ob_width(5){}
	~Map(){}

	void Obs(int obs_poz[], int gap[]);
	void Draw_border();
	int Gap();
	void go_to_xy(int x, int y);
};