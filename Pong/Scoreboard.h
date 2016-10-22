#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML\Graphics.hpp>

class Scoreboard
{
public:
	Scoreboard();
	Scoreboard(int positionX, int positionY);

	void addRow(std::string result, std::string time);
	void order();

	sf::RectangleShape drawBorder();
	sf::Text** drawTable();

private:

	int posX, posY, posYScore;
	int offsetScoreY;
	int width, height;
	sf::Font font;
	sf::Text RESULT, TIME;
	sf::Text** resultBoard;
	sf::RectangleShape border;
};


#endif // !SCOREBOARD_H

