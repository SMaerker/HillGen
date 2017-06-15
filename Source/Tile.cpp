#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	cell.setSize(sf::Vector2f(10.0, 10.0));
	cell.setFillColor(sf::Color::Transparent);
	cell.setOutlineColor(sf::Color::White);
	cell.setOutlineThickness(0.5);

	
	//font.loadFromFile("ariblk.ttf");

	//num.setFont(font);
	num.setString("x");
	num.setFillColor(sf::Color::White);
	num.setCharacterSize(10);
	
}


Tile::~Tile()
{
}


void Tile::setOffset(sf::Vector2f offset, sf::Font type){
	//num.setFont(type);
	cell.setPosition(offset.x * 10, offset.y * 10);
	//num.setPosition(cell.getPosition());
}

void Tile::setVal(int val){
	value = val;
}

sf::RectangleShape Tile::getCell(){
	return cell;
}

sf::Text Tile::getNum(){
	return num;
}

int Tile::getVal(){
	return value;
}