
//NEED TO DELETE THE NEWS SO NO MEMORY SHIT 
#include "stdafx.h"
#include "Tile.h"
#include "Coord.h"
#include "Headers.h"




int _tmain(int argc, _TCHAR* argv[]){

	srand(time(0));
	
	sf::Font testfont;
	testfont.loadFromFile("ariblk.ttf");

	const int radiusMin = 3, radiusMax = 10;
	const int width = 800, height = 600;
	const int tileWidth = 10, tileHeight = 10;

	sf::RenderWindow window(sf::VideoMode(width, height), "Hill Generation");

	sf::Time timer;
	sf::Clock clock;

	Tile **Grid = new Tile*[width / tileWidth];
	for (int r = 0; r < width / tileWidth; r++){
		Grid[r] = new Tile[height / tileHeight];
	}

	int centrals = rand() % 60 + 1;

	Coord *points = new Coord[centrals];
	
	for (int r = 0; r < width / tileWidth; r++){
		for (int c = 0; c < height / tileHeight; c++){
			//this is about to get super gross, sorry to any future person reading this. Hopefully whatever god there is 
			//can forgive me for this sin.
			for (int x = 0; x < centrals; x++){
				if (r == points[x].x && c == points[x].y){
					
					//Random point found, generate hill.
					int r = rand() % radiusMax + radiusMin;
					float z = pow(static_cast<float>(r), 2);
				
					

					Grid[r][c].setVal(static_cast<int>(z));

					

				}
			}


		}
	}

	for (int r = 0; r < width / tileWidth; r++){
		for (int c = 0; c < height / tileHeight; c++){

			Grid[r][c].setOffset(sf::Vector2f(static_cast<float>(r), static_cast<float>(c)), testfont);
			
		}
	}

	while (window.isOpen()){
		sf::Event evnt;

		while (window.pollEvent(evnt)){

			if (evnt.type == sf::Event::Closed){
				window.close();
			}



		}

		window.clear();


		for (int r = 0; r < width / tileWidth; r++){
			for (int c = 0; c < height / tileHeight; c++){
				window.draw(Grid[r][c].getCell());
				window.draw(Grid[r][c].getNum());
			}
		}

	


		window.display();


		timer += clock.restart();
	}

	return 0;
}