#include "Cell.h"

GameOfLife::GameOfLife()
{
	for (int y = 0; y < height / cellSize; y++) {
		for (int x = 0; x < height / cellSize; x++)
		{
			gameBoard[y][x] = createCell(posX + (x*cellSize), posY + (y*cellSize), cellSize);
		}
	}
}

GameOfLife::~GameOfLife()
{
}

sf::VertexArray GameOfLife::createCell(float posX, float posY, float dim)
{
	float border = 2;
	sf::VertexArray cell(sf::Quads, 8);

	//Définition des points
	cell[0].position = sf::Vector2f(posX, posY);
	cell[1].position = sf::Vector2f(posX + dim, posY);
	cell[2].position = sf::Vector2f(posX + dim, posY + dim);
	cell[3].position = sf::Vector2f(posX, posY + dim);

	//Définition de la couleur
	cell[0].color = sf::Color::White;
	cell[1].color = sf::Color::White;
	cell[2].color = sf::Color::White;
	cell[3].color = sf::Color::White;

	//Définition des points
	cell[4].position = sf::Vector2f(posX + border, posY + border);
	cell[5].position = sf::Vector2f(posX + dim - border, posY + border);
	cell[6].position = sf::Vector2f(posX + dim - border, posY + dim - border);
	cell[7].position = sf::Vector2f(posX + border, posY + dim - border);

	//Définition de la couleur
	cell[4].color = sf::Color::Green;
	cell[5].color = sf::Color::Green;
	cell[6].color = sf::Color::Green;
	cell[7].color = sf::Color::Green;

	return cell;
}


void GameOfLife::drawGameBoard(sf::RenderWindow &window)
{
	for each (sf::VertexArray var in gameBoard)
	{
		window.draw(var);
	}
}

