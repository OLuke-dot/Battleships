#include "structs.h"

//Two functions for cleaning screen and setting colors

void clear(void)
{
	COORD start;
	DWORD Written;
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	SetConsoleCursorPosition(hConsole, coordScreen);
}
void setColor(int c)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c);
}
void rewrite()
{
	p1.carrier = 1;
	p1.battleship = 2;
	p1.cruiser = 3;
	p1.destroyer = 4;
	p2.carrier = 1;
	p2.battleship = 2;
	p2.cruiser = 3;
	p2.destroyer = 4;
}
void defining()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			t.vis[i][j] = '#';
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			t.tab1_1[i][j] = c.field;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			t.tab2_1[i][j] = c.field;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			t.tab1_2[i][j] = c.field;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			t.tab2_2[i][j] = c.field;
	}
	t.shot[0] = 0;
	t.shot[1] = 0;

}
//Display of a game
void display(bool &player)
{
	int a;

	char coordY = 'A';
	cout << "\t\t\t\t\t ";
	cout << "PLAYER " << player + 1 << endl;
	//Table for shots (but not vodka)
	cout << "\t\t\t\t\t ";
	for (int x = 0; x < 10; x++)
		cout << " " << x << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t\t" << coordY;
		for (int j = 0; j < 10; j++)
		{
			if (player == 0)
				setColor(t.tab1_1[i][j]);
			if (player == 1)
				setColor(t.tab2_1[i][j]);
			Sleep(10);
			cout << "[" << t.vis[i][j] << "]";
			setColor(c.field);
		}
		cout << "\n";
		coordY = coordY + 1;
	}
	coordY = 'A';
	cout << "\n " << endl;
	//Table for ships 
	cout << "\t\t\t\t\t ";
	for (int x = 0; x < 10; x++)
		cout << " " << x << " ";
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t\t" << coordY;
		for (int j = 0; j < 10; j++)
		{
			if (player == 0)
				setColor(t.tab1_2[i][j]);

			if (player == 1)
				setColor(t.tab2_2[i][j]);
			Sleep(10);
			cout << "[" << t.vis[i][j] << "]";
			setColor(c.field);
		}
		cout << "\n";
		coordY = coordY + 1;
	}
}
