#ifndef RACKET_H
#define RACKET_H

#include <SFML\Graphics.hpp>

class Racket
{
public:
	Racket();
	Racket(sf::String texturePath);
	//~Racket();

	// MUTATEUR/ACCESSEUR
	int getPosX();
	void setPosX(int x);
	int getPosY();
	void setPosY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	int getSpeed();
	void setSpeed(int p_speed);

	void definePos();
	void defineSize();
	void defineColor();
	void moveUp(bool move, int position);
	void moveDown(bool move, int position);
	void autoPilot(int ballPosY, int directionBall, int boardHeight);

	sf::RectangleShape draw();

private:
	sf::RectangleShape racket;
	sf::Texture texture;

	int posX; int posY;
	int width; int height;
	int moveStep;
};
#endif // RACKET_H
