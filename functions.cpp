#include "functions.h"
#include "structs.h"
using namespace std;
tables t;
player1 p1, p2;
colors c;
pre ps;

//Base menu function
int menu(int &x)
{
start:;
	cout << "Welcome to the battleships!" << endl;
	cout << "Main Menu: " << endl;
	cout << "[1] - Play battleships with CPU" << endl;
	cout << "[2] - Rules of the game" << endl;
	cout << "[3] - Play with a friend (currently available)" << endl;
	cout << "[0] - Return to Desktop" << endl;
	cout << "State your choice by writing the number: ";

	cin >> x;
	if (x == 0)
		return false;
	if (x >= 4)
	{
		goto start;
	}

}
//Rule display function
bool rules()
{
	string row;
	ifstream file;
	file.open("Rules.txt");
	if (file.good())
	{
		while (getline(file, row))
			cout << row << endl;
		file.close();
	}
	else
	{
		cerr << "Fatal error. No such file or directory. Contact with administrator." << endl;
		return false;
	}
}
//Displaying board

bool listOfActions(int &x, bool &player)
{
	char lay;
	char COORD_X, align; //coordinates and char which determine either ship should be vertical or horizontal
	int COORD_Y;
start:;
	//Placing ships on the board
	cout << "[0] - Return to title menu" << endl;
	cout << "[1] - Place a ship" << endl;
	cout << "[2] - View the list of your ships" << endl;
	cout << "[3] - Help" << endl;
	cout << "Put your number here: ";
	cin >> x;
	if (x == 0)
	{
		clear();
		return x;
	}
	if (x == 2)
	{
		clear();
		if (player == 0)
			sList(0);
		
		else
			sList(1);
		display(player);
		goto start;
	}
	if (x == 3)
	{
		clear();
		rules();
		goto start;
	}
	int sT; // Ship Type
	int sizeT; // ship Size
	cout << "Would you like to use one of our pre-made sets?" << endl;
	cout << "[1] = Yes/[2] - No" << endl;
	cin >> x;
	if (x == 1)
	{
		preSets(player);
		return 0;
	}
	cout << "Select type of ship:" << endl;
	cout << "[1] - Carrier" << endl;
	cout << "[2] - Battleships" << endl;
	cout << "[3] - Cruisers" << endl;
	cout << "[4] - Destroyers" << endl;
	while (true)
	{
		sT = 0;
		cout << "Put your number here: ";
		cin >> sT;
		//continue;
		if (player == 0)
		{
			if (!p1.carrier == 0 && sT == 1)
			{
				sT = p1.size_carrier;
				break;
			}
			if (!p1.battleship == 0 && sT == 2)
			{
				sT = p1.size_battleship;
				break;
			}
			if (!p1.cruiser == 0 && sT == 3)
			{
				sT = p1.size_cruiser;
				break;
			}
			if (!p1.destroyer == 0 && sT == 4)
			{
				sT = p1.size_destroyer;
				break;
			}
			else
				cout << "You have already placed all your ships of this type!" << endl;
		}
		if (player == 1)
		{
			if (!p2.carrier == 0 && sT == 1)
			{
				sT = p1.size_carrier;
				break;
			}
			if (!p2.battleship == 0 && sT == 2)
			{
				sT = p1.size_battleship;
				break;
			}
			if (!p2.cruiser == 0 && sT == 3)
			{
				sT = p1.size_cruiser;
				break;
			}
			if (!p2.destroyer == 0 && sT == 4)
			{
				sT = p1.size_destroyer;
				break;
			}
			else
				cout << "You have already placed all your ships of this type!" << endl;
		}
		
	}
	bool i = player;
	do
	{

		cout << "Put coordinates here: ";
		cin >> align;
		cin >> COORD_X;
		cin >> COORD_Y;
		COORD_X = COORD_X - var;

	} while (placeCheck(COORD_X, COORD_Y, align, sT, i) == 1);
	if (player == 0)
	{
		if (sT == p1.size_carrier)
		{
			p1.carrier--;
		}
		if (sT == p1.size_battleship)
		{
			p1.battleship--;
		}
		if (sT == p1.size_cruiser)
		{
			p1.cruiser--;
		}
		if (sT == p1.size_destroyer)
		{
			p1.destroyer--;
		}
		if (align == 104 || align == 72)//Ascii number for 'h' and 'H'
		{
			for (int i = 0; i < sT; i++)
				t.tab1_2[COORD_X][COORD_Y + i] = c.ship;
		}
		if (align == 118 || align == 86) //Ascii number for 'v' and 'V'
		{
			for (int i = 0; i < sT; i++)
				t.tab1_2[COORD_X + i][COORD_Y] = c.ship;
		}
	}
	if (player == 1)
	{
		if (sT == p2.size_carrier)
		{
			p2.carrier--;
		}
		if (sT == p2.size_battleship)
		{
			p2.battleship--;
		}
		if (sT == p2.size_cruiser)
		{
			p2.cruiser--;
		}
		if (sT == p2.size_destroyer)
		{
			p2.destroyer--;
		}
		if (align == 104 || align == 72)//Ascii number for 'h' and 'H'
		{
			for (int i = 0; i < sT; i++)
				t.tab2_2[COORD_X][COORD_Y + i] = c.ship;
		}
		if (align == 118 || align == 86) //Ascii number for 'v' and 'V'
		{
			for (int i = 0; i < sT; i++)
				t.tab2_2[COORD_X + i][COORD_Y] = c.ship;
		}
	}

	sT = 0;
	if (p1.battleship == 0 && p1.carrier == 0 && p1.cruiser == 0 && p1.destroyer == 0)
	{
		if (p2.battleship == 0 && p2.carrier == 0 && p2.cruiser == 0 && p2.destroyer == 0)
			return x = 4;
	}

}
void sList(bool player)
{
	if (player == 0)
	{
		cout << "Carriers: " << p1.carrier << endl;
		cout << "Battleships: " << p1.battleship << endl;
		cout << "Crusier: " << p1.cruiser << endl;
		cout << "Destroyer: " << p1.destroyer << endl;
	}
	if (player == 1)
	{
		cout << "Carriers: " << p2.carrier << endl;
		cout << "Battleships: " << p2.battleship << endl;
		cout << "Crusier: " << p2.cruiser << endl;
		cout << "Destroyer: " << p2.destroyer << endl;
	}
}
bool placeCheck(int x, int y, int a, int sT, bool player)
{
	bool z = 0;
	if (x < 0 || x >= 10 || y < 0 || y >= 10 || !a == 118 || !a == 104 || !a == 86 || !a == 72)
		z = 1;
	if ((a == 118 || a == 86) && (x + sT > 9)) //v
		z = 1;
	if ((a == 104 || a == 72) && (y + sT > 9)) //h
		z = 1;
	if (a == 118 || a == 86)
	{
		for (int i = 0; i < sT; i++)
		{
			if (placeCheck2(x + i, y, player) == 1)
				z = 1;
		}
	}
	if (a == 104 || a == 72)
	{
		for (int i = 0; i < sT; i++)
		{
			if (placeCheck2(x, y + i, player) == 1)
				z = 1;
		}
	}
	if (player == 0)
	{
		
		if (a == 118 || a == 86) // v
		{
			for (int i = 0; i < sT; i++)
			{
				if (t.tab1_2[x + i][y] == c.ship)
					z = 1;
			}
		}
		if (a == 104 || a == 72) // h
		{
			for (int i = 0; i < sT; i++)
			{
				if (t.tab1_2[x][y + i] == c.ship)
					z = 1;
			}
		}

	}
	if (player == 1)
	{
		if (a == 118 || a == 86) // v
		{
			for (int i = 0; i < sT; i++)
			{
				if (t.tab2_2[x + i][y] == c.ship)
					z = 1;
			}
		}
		if (a == 104 || a == 72) // h
		{
			for (int i = 0; i < sT; i++)
			{
				if (t.tab2_2[x][y + i] == c.ship)
					z = 1;
			}
		}
	}
	if (z == 1)
		cout << "Incorect parameters.Please try again" << endl;
	return z;
}
bool placeCheck2(int x, int y, bool player)
{
	bool z = 0;
	if (player == 0)
	{
			if (x == 0 && y == 0) // top left corner
			{
				if (t.tab1_2[x + 1][y] == c.ship || t.tab1_2[x][y + 1] == c.ship)
					z = 1;
			}
			if (x == 0 && y == 9) // top right corner
			{
				if (t.tab1_2[x + 1][y] == c.ship)
					z = 1;
			}
			if (x == 9 && y == 0) //bottom left corner
			{
				if (t.tab1_2[x][y + 1] == c.ship)
					z = 1;
			}
			if (x == 9 && y == 9)
			{
				if (t.tab1_2[x - 1][y] == c.ship || t.tab1_2[x][y - 1] == c.ship)
					z = 1;
			}
			//Walls
			if (x == 0 && (t.tab1_2[x + 1][y] == c.ship || t.tab1_2[x][y + 1] == c.ship || t.tab1_2[x][y - 1] == c.ship)) // Top
				z = 1;
			if (x == 9 && (t.tab1_2[x - 1][y] == c.ship || t.tab1_2[x][y + 1] == c.ship || t.tab1_2[x][y - 1] == c.ship)) // bottom
				z = 1;
			if (y == 0 && (t.tab1_2[x][y + 1] == c.ship || t.tab1_2[x + 1][y] == c.ship || t.tab1_2[x - 1][y] == c.ship)) // Left
				z = 1;
			if (y == 9 && (t.tab1_2[x][y - 1] == c.ship || t.tab1_2[x + 1][y] == c.ship || t.tab1_2[x - 1][y] == c.ship)) // Top
				z = 1;
			else
			{
				if (t.tab1_2[x][y + 1] == c.ship || t.tab1_2[x][y - 1] == c.ship || t.tab1_2[x + 1][y] == c.ship || t.tab1_2[x - 1][y] == c.ship)
						z = 1;
			}
	}
	if (player == 1)
	{
		if (x == 0 && y == 0) // top left corner
		{
			if (t.tab2_2[x + 1][y] == c.ship || t.tab2_2[x][y + 1] == c.ship)
				z = 1;
		}
		if (x == 0 && y == 9) // top right corner
		{
			if (t.tab2_2[x + 1][y] == c.ship)
				z = 1;
		}
		if (x == 9 && y == 0) //bottom left corner
		{
			if (t.tab2_2[x][y + 1] == c.ship)
				z = 1;
		}
		if (x == 9 && y == 9)
		{
			if (t.tab2_2[x - 1][y] == c.ship || t.tab2_2[x][y - 1])
				z = 1;
		}
		// Player cant place a ship in a bottom right corner
		//Walls
		if (x == 0 && (t.tab2_2[x + 1][y] == c.ship || t.tab2_2[x][y + 1] == c.ship || t.tab2_2[x][y - 1] == c.ship)) // Top
			z = 1;
		if (x == 9 && (t.tab2_2[x - 1][y] == c.ship || t.tab2_2[x][y + 1] == c.ship || t.tab2_2[x][y - 1] == c.ship)) // bottom
			z = 1;
		if (y == 0 && (t.tab2_2[x][y + 1] == c.ship || t.tab2_2[x + 1][y] == c.ship || t.tab2_2[x - 1][y] == c.ship)) // Left
			z = 1;
		if (y == 9 && (t.tab2_2[x][y - 1] == c.ship || t.tab2_2[x + 1][y] == c.ship || t.tab2_2[x - 1][y] == c.ship)) // Top
			z = 1;
		else
		{
			if (t.tab2_2[x][y + 1] == c.ship || t.tab2_2[x][y - 1] == c.ship || t.tab2_2[x + 1][y] == c.ship || t.tab2_2[x - 1][y] == c.ship)
					z = 1;
		}
	}
	
	return z;
}
void preSets(bool player)
{
	cout << "\t\t\t\t Set 1" << endl;
	//display(ps.set1);
}