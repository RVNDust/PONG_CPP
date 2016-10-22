#include <SFML\Graphics.hpp>
#include "Cell.h"

using namespace std;

int main()
{
	sf::Font font;
	if (!font.loadFromFile("CODE_Bold.otf"));
	{
		
	}

	sf::Text title;
	title.setFont(font);
	title.setCharacterSize(24);
	title.setString("Game Of Life");
	title.setPosition(320, 0);

	// création d'un tableau de 3 vertex définissant un triangle
	sf::VertexArray bandeau(sf::Quads, 4);

	// on définit la position des sommets du triangle
	bandeau[0].position = sf::Vector2f(10, 50);
	bandeau[1].position = sf::Vector2f(790, 50);
	bandeau[2].position = sf::Vector2f(790, 100);
	bandeau[3].position = sf::Vector2f(10, 100);

	// on définit la couleur des sommets du triangle
	bandeau[0].color = sf::Color::Red;
	bandeau[1].color = sf::Color::Blue;
	bandeau[2].color = sf::Color::Red;
	bandeau[3].color = sf::Color::Blue;

	GameOfLife gameBoard;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Of Life", sf::Style::Default);


	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Préparation prochain affichage
		window.clear();
		
		window.draw(title);
		gameBoard.drawGameBoard();
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

	return 0;
}