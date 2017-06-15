

#include "stdafx.h"
#include "Tile.h"

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <SFML\Graphics.hpp>


int _tmain(int argc, _TCHAR* argv[]){

	srand(time(0));


	
	sf::Font testfont;
	

	testfont.loadFromFile("ariblk.ttf");

	

	int width = 800, height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "Hill Generation");

	sf::Time timer;
	sf::Clock clock;

	Tile **Grid = new Tile*[800 / 10];

	for (int r = 0; r < 80; r++){
		Grid[r] = new Tile[60];
	}

	for (int r = 0; r < 80; r++){
		for (int c = 0; c < 60; c++){
			Grid[r][c].setOffset(sf::Vector2f(static_cast<float>(r), static_cast<float>(c)), testfont);
			Grid[r][c].setVal(rand() % 9 + 1);
			printf("%i ", Grid[r][c].getVal());
		}
		printf("\n");
	}

	while (window.isOpen()){
		sf::Event evnt;

		while (window.pollEvent(evnt)){

			if (evnt.type == sf::Event::Closed){
				window.close();
			}



		}

		window.clear();

		//draw here
		for (int r = 0; r < 80; r++){
			for (int c = 0; c < 60; c++){
				window.draw(Grid[r][c].getCell());
				window.draw(Grid[r][c].getNum());
			}
		}

	


		window.display();


		timer += clock.restart();
	}

	return 0;
}