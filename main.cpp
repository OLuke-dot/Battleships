//This is a main file in which the whole game is starting

#include <iostream>
#include "structs.h"
#include "functions.h"
#include "cpuGame.h"
#include "pVpGame.h"

using namespace std;

void nextPlayer() //Short function for switching between players
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
int main() //Main file
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