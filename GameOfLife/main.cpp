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

	// cr�ation d'un tableau de 3 vertex d�finissant un triangle
	sf::VertexArray bandeau(sf::Quads, 4);

	// on d�finit la position des sommets du triangle
	bandeau[0].position = sf::Vector2f(10, 50);
	bandeau[1].position = sf::Vector2f(790, 50);
	bandeau[2].position = sf::Vector2f(790, 100);
	bandeau[3].position = sf::Vector2f(10, 100);

	// on d�finit la couleur des sommets du triangle
	bandeau[0].color = sf::Color::Red;
	bandeau[1].color = sf::Color::Blue;
	bandeau[2].color = sf::Color::Red;
	bandeau[3].color = sf::Color::Blue;

	GameOfLife gameBoard;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Of Life", sf::Style::Default);


	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Pr�paration prochain affichage
		window.clear();
		
		window.draw(title);
		gameBoard.drawGameBoard();
		// fin de la frame courante, affichage de tout ce qu'on a dessin�
		window.display();
	}

	return 0;
}