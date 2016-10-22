#include "Ball.h"

Ball::Ball()
{
	speed = 0; moveX = 0; moveY = 0;
	initPosX = 500; initPosY = 500;
	ball.setFillColor(sf::Color::White);
}

#pragma region ACCESSEUR / MUTATEURS

int Ball::getPosX()
{
	return posX;
}

void Ball::setPosX(int x)
{
	posX = x;
	ball.setPosition(posX, posY);
}

int Ball::getPosY()
{
	return posY;
}

void Ball::setPosY(int y)
{
	posY = y;
	ball.setPosition(posX, posY);
}

int Ball::getWidth()
{
	return width;
}

void Ball::setWidth(int width)
{
	Ball::width = width;
	ball.setSize(sf::Vector2f(width, height));
}

int Ball::getHeight()
{
	return height;
}

void Ball::setHeight(int height)
{
	Ball::height = height;
	ball.setSize(sf::Vector2f(width, height));
}

float Ball::getSpeed()
{
	return speed;
}

void Ball::setSpeed(float speed)
{
	Ball::speed = speed;
}

float Ball::getMoveX()
{
	return moveX;
}

void Ball::setMoveX(float moveX)
{
	Ball::moveX = moveX;
}

float Ball::getMoveY()
{
	return moveY;
}

void Ball::setMoveY(float moveY)
{
	Ball::moveY = moveY;
}
#pragma endregion

#pragma region FONCTIONS
sf::RectangleShape Ball::draw()
{
	return ball;
}

/*
*	Permet la détection de la collision contre les bords supérieurs et inférieurs du terrain
*/
bool Ball::isOutBoard(int supBound, int infBound)
{
	bool returnValue = false;
	if (posY < supBound)
	{
		setPosY(supBound);
		moveY = -moveY;
		returnValue = true;
	}
	else if (posY > infBound - height)
	{ 
		setPosY(infBound - height);
		moveY = -moveY;
		returnValue = true;
	}
	return returnValue;
}

bool Ball::isNewDrection(int p_racketAPosY, int p_racketBPosY, int p_racketAPosX, int p_racketBPosX, int p_racketWidth, int p_racketHeight)
{
	bool returnValue = false;
	
	if (isOnRacket(p_racketAPosX, p_racketAPosY, p_racketWidth, p_racketHeight)) {
		std::string direction = positionOnRacket(p_racketAPosY, p_racketHeight);
		if (direction == "HAUT") {
			moveX = 2 * speed;
			moveY = -3 * speed;
		}
		else if (direction == "MIHAUT") {
			moveX = 2 * speed;
			moveY = -2 * speed;
		}
		else if (direction == "CENTRE") {
			moveX = 3 * speed;
			moveY = 0 * speed;
		}
		else if (direction == "MIBAS") {
			moveX = 2 * speed;
			moveY = 2 * speed;
		}
		else if (direction == "BAS") {
			moveX = 2 * speed;
			moveY = 3 * speed;
		}
		returnValue = true;
	}
	else if (isOnRacket(p_racketBPosX, p_racketBPosY, p_racketWidth, p_racketHeight)) {
		std::string direction = positionOnRacket(p_racketBPosY, p_racketHeight);
		if (direction == "HAUT") {
			moveX = -2 * speed;
			moveY = -3 * speed;
		}
		else if (direction == "MIHAUT") {
			moveX = -2 * speed;
			moveY = -2 * speed;
		}
		else if (direction == "CENTRE") {
			moveX = -3 * speed;
			moveY = 0 * speed;
		}
		else if (direction == "MIBAS") {
			moveX = -2 * speed;
			moveY = 2 * speed;
		}
		else if (direction == "BAS") {
			moveX = -2 * speed;
			moveY = 3 * speed;
		}
		returnValue = true;
	}
	return returnValue;
}

bool Ball::isOnRacket(int p_racketPosX, int p_racketPosY, int p_racketWidth, int p_racketHeight)
{
	if (!(p_racketPosX > posX + height || p_racketPosX < posX - p_racketWidth
		|| p_racketPosY > posY + height || p_racketPosY < posY - p_racketHeight))
		return true;

	return false;
}

std::string Ball::positionOnRacket(int p_racketPosY, int p_racketHeight)
{
	int sizePosRacket = p_racketHeight / 5;

	if (posY > p_racketPosY - p_racketHeight && posY < p_racketPosY + sizePosRacket) {
		return "HAUT";
	}
	else if (posY >= p_racketPosY + sizePosRacket && posY < p_racketPosY + sizePosRacket * 2) {
		return "MIHAUT";
	}
	else if (posY >= p_racketPosY + p_racketHeight - sizePosRacket * 2 && posY < p_racketPosY + p_racketHeight - sizePosRacket) {
		return "MIBAS";
	}
	else if (posY >= p_racketPosY + p_racketHeight - sizePosRacket && posY < p_racketPosY + p_racketHeight) {
		return "MIBAS";
	}
	return "CENTRE";
}

bool Ball::isScored(int leftBound, int rightBound, std::string *starter)
{
	if (posX <= leftBound)
	{
		//Ajouter le compte des scores
		speed = 0;
		(*starter) = "ia";
		posX = initPosX;
		posY = initPosY;
		return true;
	}
	else if (posX >= rightBound - width)
	{
		//Ajouter le compte des scores
		speed = 0;
		(*starter) = "player";
		setPosX(initPosX);
		setPosY(initPosY);
		return true;
	}
	return false;
}

void Ball::move()
{
	setPosX(posX + moveX * speed);
	setPosY(posY + moveY * speed);
}

void Ball::speedUp()
{
	speed += 0.05;
}
void Ball::initBall(Racket * racket, bool left)
{
	setPosY(racket->getPosY() + racket->getHeight()/2);
	speed = 1;
	if (left)
	{
		setPosX(racket->getPosX() + racket->getWidth());
		moveX = 2;
		moveY = 2;
	}
	else
	{
		setPosX(racket->getPosX());
		moveX = -2;
		moveY = 2;
	}
}

#pragma endregion