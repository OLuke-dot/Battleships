#include <iostream>
#include "structs.h"
#include "functions.h"
#include "cpuGame.h"
#include "pVpGame.h"
using namespace std;
void test()
{
	for (int i = 0; i < 5; i++)
	{
		t.tab1_2[0][i] = c.ship;
		t.tab2_2[0][i] = c.ship;
	}
	p1.carrier = 1;
	p2.carrier = 1;
	p1.battleship = 0;
	p1.cruiser = 0;
	p1.destroyer = 0;
	p2.battleship = 0;
	p2.cruiser = 0;
	p2.destroyer = 0;
}
void nextPlayer()
{
	char x;
	cout << "\t\t\t\t\t";
	cout << "NEXT";
	Sleep(60);
	cout << "PLAYER" << endl;
	cout << "Type 'Y' when you are ready" << endl;
	cin >> x;
	clear();
}
int main()
{
	int x = 0;
	bool p1 = 0;
	bool p2 = 1;
	bool c;
	int q = 0;
	int r = 0;
	setColor(2);
start:;
	while (true)
	{
		menu(x);
		if (x == 0)
		{
			break;
		}
		if (x == 3)
		{
			defining();
			while (true)
			{
				display(p1);
				listOfActions(x, p1);
				clear();
				nextPlayer();
				display(p2);
				listOfActions(x, p2);
				clear();
				nextPlayer();
				if (x == 0)
					return false;
				if (x == 4)
					break;
			}
			//test();
			rewrite();
				while (majorCheck() == true)
				{
					
					do
					{
						c = 0;
						display(p1);
						pMenu(x);
						if (x == 1)
						{
							shot(p1);
							if (checking(p1) == 1)
								c = 1;
						}
						if (x == 2)
							sList(p1);
					} while (c == 0);
					
					clear();
					nextPlayer();
					
					
					do
					{
						c = 0;
						display(p2);
						pMenu(x);
						if (x == 1)
						{
							shot(p2);
							if (checking(p2) == 1)
								c = 1;
						}
						if (x == 2)
							sList(p2);
					} while (c == 0);
					clear();
					majorCheck();
				}

		}
		if (x == 2)
			rules();
		if (majorCheck() == false)
			return false;
	}
return 0;
}