#pragma once
#include "Headers.h"


class Tile
{
public:
	Tile();
	~Tile();


	void setOffset(sf::Vector2f offset, sf::Font type);
	void setVal(int val);
	sf::RectangleShape getCell();
	sf::Text getNum();
	int getVal();

private:
	int value = 0;
	sf::RectangleShape cell;

	sf::Font font;
	sf::Text num;

};

