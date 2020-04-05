#include "pVpGame.h"
#include "structs.h"


void pMenu(int &x)
{
	x = 0;
	cout << "List of Actions: " << endl;
	cout << "[1] - Fire your shot" << endl;
	cout << "[2] - View list of your ships" << endl;
	cout << "[0] - End game and leave to menu" << endl;
	cout << "State your choice by writing the number: ";
	cin >> x;
}
bool shot(bool &player)
{
	char COORD_X;
	int COORD_Y;
start:;
	cout << "Put Coordinates here: ";
	cin >> COORD_X;
	cin >> COORD_Y;
	COORD_X = COORD_X - var;
	if (COORD_X < 0 || COORD_X >= 10 || COORD_Y < 0 || COORD_Y >= 10 )
	{
		cout << "Incorect parameters. Please try again" << endl;
		goto start;
	}
	
	t.shot[0] = COORD_X;
	t.shot[1] = COORD_Y;
	if (player == 0)
		t.tab1_1[COORD_X][COORD_Y] = c.shot;
	if (player == 1)
		t.tab2_1[COORD_X][COORD_Y] = c.shot;
	return true;
}
bool checking(bool &player)
{
	int w = 0;
	int Q;
	//bool p;
	if (player == 0)
	{
		if (t.tab2_2[t.shot[0]][t.shot[1]] == c.ship)
		{
			cout << "Target Hit !!!" << endl;
			t.tab1_1[t.shot[0]][t.shot[1]] = c.s_ship;
			t.tab2_2[t.shot[0]][t.shot[1]] = c.s_ship;
			w = 1;
			//corners
			if (t.shot[0] == 0 && t.shot[1] == 0) // top left corner
			{
				if (t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship)
					w++;
			}
			if (t.shot[0] == 0 && t.shot[1] == 9) // top right corner
			{
				if (t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship)
					w++;
			}
			if (t.shot[0] == 9 && t.shot[1] == 0) //bottom left corner
			{
				if (t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab2_2[t.shot[0] - 1][t.shot[1]])
					w++;
			}
			if (t.shot[0] == 9 && t.shot[1] == 9)
			{
				if (t.tab2_2[t.shot[0] - 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship)
					w++;
			}
			//Walls
			if (t.shot[0] == 0 && (t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship)) // Top
				w++;
			if (t.shot[0] == 9 && (t.tab2_2[t.shot[0] - 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship)) // bottom
				w++;
			if (t.shot[1] == 0 && (t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0] - 1][t.shot[1]] == c.ship)) // Left
				w++;
			if (t.shot[1] == 9 && (t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship || t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0] - 1][t.shot[1]] == c.ship)) // Top
				w++;
			else
			{
			//Ending calculations	
				if (t.tab2_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab2_2[t.shot[0]][t.shot[1] - 1] == c.ship || t.tab2_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab2_2[t.shot[0] - 1][t.shot[1]] == c.ship)
					w++;
			}
		}
		else
		{
			cout << "Miss!!!" << endl;
			return 1;
		}
		if (w == 1)
		{
			cout << "You have sunken the ship!!!" << endl;
			//p = 0;
			shipCheck(t.shot[0], t.shot[1], player);
			cin >> Q;
			return 0;
		}
		if (w > 1)
			return 0;
	}
	if (player == 1)
	{
		if (t.tab1_2[t.shot[0]][t.shot[1]] == c.ship)
		{
			cout << "Target Hit !!!" << endl;
			t.tab1_2[t.shot[0]][t.shot[1]] = c.s_ship;
			t.tab2_1[t.shot[0]][t.shot[1]] = c.s_ship;
			w = 1;
			//corners
			if (t.shot[0] == 0 && t.shot[1] == 0) // top left corner
			{
				if (t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship)
					w++;
			}
			if (t.shot[0] == 0 && t.shot[1] == 9) // top right corner
			{
				if (t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship)
					w++;
			}
			if (t.shot[0] == 9 && t.shot[1] == 0) //bottom left corner
			{
				if (t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab1_2[t.shot[0] - 1][t.shot[1]])
					w++;
			}
			if (t.shot[0] == 9 && t.shot[1] == 9)
			{
				if (t.tab1_2[t.shot[0] - 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship)
					w++;
			}
			//Walls
			if (t.shot[0] == 0 && (t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship)) // Top
				w++;
			if (t.shot[0] == 9 && (t.tab1_2[t.shot[0] - 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship)) // bottom
				w++;
			if (t.shot[1] == 0 && (t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0] - 1][t.shot[1]] == c.ship)) // Left
				w++;
			if (t.shot[1] == 9 && (t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship || t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0] - 1][t.shot[1]] == c.ship)) // Top
				w++;
			else
			{
				//Ending calculations	
				if (t.tab1_2[t.shot[0]][t.shot[1] + 1] == c.ship || t.tab1_2[t.shot[0]][t.shot[1] - 1] == c.ship || t.tab1_2[t.shot[0] + 1][t.shot[1]] == c.ship || t.tab1_2[t.shot[0] - 1][t.shot[1]] == c.ship)
					w++;
			}
		}
		else
		{
			cout << "Miss!!!" << endl;
			return 1;
		}
		if (w == 1)
		{
			cout << "You have sunken the ship!!!" << endl;
			//p = 0;
			shipCheck(t.shot[0], t.shot[1], player);
			cin >> Q;
			return 0;
		}
		if (w > 1)
			return 0;
	}
}
void shipCheck(int x, int y, bool player)
{
	int q = 1;
	if (player == 0) // First Player
	{
		if (t.tab1_2[x + 1][y] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab1_2[x + q][y] == c.s_ship);
		}
		if (t.tab1_2[x - 1][y] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab1_2[x - q][y] == c.s_ship);
		}
		if (t.tab1_2[x][y + 1] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab1_2[x][y + q] == c.s_ship);
		}
		if (t.tab1_2[x][y - 1] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab1_2[x][y -q] == c.s_ship);
		}
		if (q == p1.size_battleship)
			p1.battleship--;
		if (q == p1.size_carrier)
			p1.carrier--;
		if (q == p1.size_cruiser)
			p1.cruiser--;
		if (q == p1.size_destroyer)
			p1.destroyer--;
	}

	if (player == 1) // Second Player
	{
		if (t.tab2_1[x + 1][y] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab2_1[x + q][y] == c.s_ship);
		}
		if (t.tab2_1[x - 1][y] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab2_1[x - q][y] == c.s_ship);
		}
		if (t.tab2_1[x][y + 1] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab2_1[x][y + q] == c.s_ship);
		}
		if (t.tab2_1[x][y - 1] == c.s_ship)
		{
			do
			{
				q++;

			} while (t.tab2_1[x][y - q] == c.s_ship);
		}
		if (q == p2.size_battleship)
			p2.battleship--;
		if (q == p2.size_carrier)
			p2.carrier--;
		if (q == p2.size_cruiser)
			p2.cruiser--;
		if (q == p2.size_destroyer)
			p2.destroyer--;
	}
}
bool majorCheck()
{
	if (p1.battleship == 0 && p1.carrier == 0 && p1.cruiser == 0 && p1.destroyer == 0)
	{
			cout << "PLAYER 1 WINS !!!" << endl;
			return false;
	}
	if (p2.battleship == 0 && p2.carrier == 0 && p2.cruiser == 0 && p2.destroyer == 0)
	{
			cout << "PLAYER 2 WINS !!!" << endl;
			return false;
	}
	else
		return true;
}
