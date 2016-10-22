
#include "Tilemap.h"


int main()
{
	// on crée la fenêtre
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

	// on définit le niveau à l'aide de numéro de tuiles
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
		0, 20, 20, 20, 20, 20, 20, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		20, 20, 0, 0, 0, 0, 0, 0, 37, 37, 37, 37, 37, 37, 37, 37,
		0, 20, 0, 0, 2, 0, 37, 37, 37, 0, 20, 20, 20, 0, 0, 0,
		0, 20, 20, 0, 37, 37, 37, 0, 0, 0, 20, 20, 20, 2, 0, 0,
		0, 0, 20, 0, 37, 0, 2, 2, 0, 0, 20, 20, 20, 20, 2, 0,
		2, 0, 20, 0, 37, 0, 2, 2, 2, 0, 20, 20, 20, 20, 20, 20,
		0, 0, 20, 0, 37, 2, 2, 2, 0, 0, 0, 0, 20, 20, 20, 20,
	};

	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
	if (!map.load("Woodland_ground.png", sf::Vector2u(32, 32), level, 16, 8))
		return -1;

	// on fait tourner la boucle principale
	while (window.isOpen())
	{
		// on gère les évènements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// on dessine le niveau
		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}