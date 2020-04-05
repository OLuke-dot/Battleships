#pragma once
#include <iostream>
#include <windows.h>
#define var 65;
using namespace std;
//This file is for all functons and variables used all over the program


//Structs determining tables and colors for all of actions
 typedef struct colors
{
	int field = 2;	//Green
	int ship = 1;	//Blue
	int shot = 6;	//Yellow
	int s_ship = 4;		//sunken ship
};
  typedef struct player1
{
	int carrier = 1;
	int battleship = 2;
	int cruiser = 3;
	int destroyer = 4;

	int size_carrier = 5;
	int size_battleship = 4;
	int size_cruiser = 3;
	int size_destroyer = 2;
};
 typedef struct tables
{ 
	char vis[10][10]; // Visual table filled with #
	int tab1_1[10][10], tab2_1[10][10]; // Tabs containing info about shots
	int tab1_2[10][10], tab2_2[10][10]; // Tabs containg info about ships
	int shot[2];

};
 typedef struct pre
 {
	int set1[10][10];
	int set2[10][10];
	int set3[10][10];
	int set4[10][10];
	int set5[10][10];
 };
void setColor(int c);
void defining();
void clear(void);
void rewrite();
void display(bool &player);

extern colors c;
extern player1 p1, p2;
extern tables t;
extern pre ps;