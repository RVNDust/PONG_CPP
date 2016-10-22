#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>
#include "Racket.h"
#include <string.h>

class Ball
{
public:
	Ball();
	//~Ball();

	// MUTATEUR/ACCESSEUR
	int getPosX();
	void setPosX(int x);
	int getPosY();
	void setPosY(int y);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	float getSpeed();
	void setSpeed(float speed);
	float getMoveX();
	void setMoveX(float moveX);
	float getMoveY();
	void setMoveY(float moveY);

	bool isOutBoard(int supBound, int infBound);

	bool isNewDrection(int p_racketAPosY, int p_racketBPosY, int p_racketAPosX, int p_racketBPosX, int p_racketWidth, int p_racketHeight);
	bool isOnRacket(int p_racketAPosY, int p_racketBPosY, int p_racketWidth, int p_racketHeight);
	std::string positionOnRacket(int p_racketPosY, int p_racketHeight);

	bool isScored(int leftBound, int rightBound, std::string *starter);
	void move();
	void speedUp();
	void initBall(Racket *racket, bool left);

	sf::RectangleShape draw();

private:
	sf::RectangleShape ball;

	int initPosX; int initPosY;
	int posX; int posY;
	int width; int height;
	float speed; 
	float moveX; float moveY;
};


#endif // !BALL_H
