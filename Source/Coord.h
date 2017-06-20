#include "stdafx.h"
#include "Headers.h"
struct Coord{
	Coord(){
		x = rand() % 80;
		y = rand() % 60;
	}

	int x = 0;
	int y = 0;

};