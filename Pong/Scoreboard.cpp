#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
	posX = 500; posY = 500; posYScore = posY + 50;
	width = 200; height = 600;


	font.loadFromFile("CODE_Bold.otf");
	RESULT.setString("RESULTATS");
	TIME.setString("TEMPS");
	RESULT.setFont(font);
	TIME.setFont(font);
	RESULT.setCharacterSize(15);
	TIME.setCharacterSize(15);

	resultBoard[0][0] = RESULT; resultBoard[0][1] = TIME;

	border.setPosition(posX, posY);
	border.setSize(sf::Vector2f(width, height));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineThickness(5);
	border.setOutlineColor(sf::Color::White);
}

Scoreboard::Scoreboard(int positionX, int positionY)
{
	posX = positionX; posY = positionY; posYScore = posY + 50;
	width = 200; height = 600;

	font.loadFromFile("CODE_Bold.otf");
	RESULT.setString("RESULTATS");
	TIME.setString("TEMPS");
	RESULT.setFont(font);
	TIME.setFont(font);
	RESULT.setCharacterSize(15);
	TIME.setCharacterSize(15);

	resultBoard[0][0] = RESULT; resultBoard[0][1] = TIME;

	border.setPosition(posX, posY);
	border.setSize(sf::Vector2f(width, height));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineThickness(5);
	border.setOutlineColor(sf::Color::White);
}

void Scoreboard::addRow(std::string result, std::string time)
{

	resultBoard[1][0].setFont(font);
	resultBoard[1][0].setString(result);
	resultBoard[1][0].setPosition(sf::Vector2f(posX, posYScore + offsetScoreY));
	resultBoard[1][0].setColor(sf::Color::Red);

	resultBoard[1][1].setFont(font);
	resultBoard[1][1].setString(time);
	resultBoard[1][1].setPosition(sf::Vector2f(posX + width/2, posYScore + offsetScoreY));
	resultBoard[1][1].setColor(sf::Color::Red);
}

sf::RectangleShape Scoreboard::drawBorder()
{
	return border;
}

sf::Text** Scoreboard::drawTable()
{
	return resultBoard;
}
