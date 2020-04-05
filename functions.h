#pragma once;
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <windows.h>
#define var 65

int menu(int &x);
bool rules();
bool listOfActions(int &x, bool &player);
void sList(bool player);
bool placeCheck(int x, int y, int a, int sT, bool player);
bool placeCheck2(int x, int y, bool player);
void preSets(bool player);