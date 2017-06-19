

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

	const int radiusMin = 3, radiusMax = 10;
	

	int width = 800, height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "Hill Generation");

	sf::Time timer;
	sf::Clock clock;

	Tile **Grid = new Tile*[800 / 10];
	for (int r = 0; r < 80; r++){
		Grid[r] = new Tile[60];
	}

	////////////////////////////
	int d = rand() % 60 + 1;

	int *pointsX = new int[d], *pointsY = new int[d];

	for (int c = 0; c < d; c++){
		pointsX[c] = rand() % 80;
		pointsY[c] = rand() % 60;
	//	printf("%i - %i\n", pointsX[c], pointsY[c]);
	}
	////////////////////////////
	////////////////////////////
	for (int r = 0; r < 80; r++){
		for (int c = 0; c < 60; c++){
			//this is about to get super gross, sorry to any future person reading this. Hopefully whatever god there is 
			//can forgive me for this sin.
			for (int x = 0; x < d; x++){
				if (r == pointsX[x] && c == pointsY[x]){
					
					//Random point found, generate hill.
					int r = rand() % radiusMax + radiusMin;
					float z = pow(static_cast<float>(r), 2);
				
					

					Grid[r][c].setVal(static_cast<int>(z));

					

				}
			}


		}
	}
	////////////////////////////
	for (int r = 0; r < 80; r++){
		for (int c = 0; c < 60; c++){
			//Grid[r][c].setVal(0);

			Grid[r][c].setOffset(sf::Vector2f(static_cast<float>(r), static_cast<float>(c)), testfont);
			
			//printf("%i ", Grid[r][c].getVal());
		}
	//	printf("\n");
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