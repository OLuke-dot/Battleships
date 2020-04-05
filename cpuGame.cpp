#include "cpuGame.h"
int tMenu(int &x)
{
	x = 0;
	cout << "List of Actions: " << endl;
	cout << "[1] - Fire your shot" << endl;
	cout << "[2] - View list of your ships" << endl;
	cout << "[3] - View how many ships you have already sunked" << endl;
	cout << "[0] - End game and leave to menu" << endl;
	cout << "State your choice by writing the number: ";
	cin >> x;
	return x;
}


