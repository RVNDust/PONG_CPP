#ifndef BOARD_H
#define BOARD_H

#include <SFML\Graphics.hpp>

class Board
{
public:
	Board();
	//~Board()

	// MUTATEUR/ACCESSEUR
	int getPosX();
	void setPosX(int x);
	int getPosY();
	void setPosY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);

	// FONCTIONS
	sf::RectangleShape draw();

private:
	int posX; int posY;
	int width; int height;
	sf::RectangleShape board;

};
#endif //BOARD_H