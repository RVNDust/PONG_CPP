#include "Racket.h"

Racket::Racket()
{
	posX = 100;  posY = 100;
	height = 60;  width = 10;
	moveStep = 6;

	racket.setPosition(posX, posY);
	racket.setSize(sf::Vector2f(width, height));
	racket.setFillColor(sf::Color::White);
}

Racket::Racket(sf::String texturePath)
{
	posX = 100;  posY = 100;
	height = 60;  width = 10;
	moveStep = 6;

	texture.loadFromFile(texturePath);

	racket.setPosition(posX, posY);
	racket.setSize(sf::Vector2f(width, height));
	racket.setTexture(&texture);
}


#pragma region ACCESSEUR / MUTATEURS

int Racket::getPosX()
{
	return posX;
}

void Racket::setPosX(int x)
{
	posX = x;
	racket.setPosition(posX, posY);
}

int Racket::getPosY()
{
	return posY;
}

void Racket::setPosY(int y)
{
	posY = y;
	racket.setPosition(posX, posY);
}

int Racket::getWidth()
{
	return width;
}

void Racket::setWidth(int width)
{
	Racket::width = width;
	racket.setSize(sf::Vector2f(width, height));
}

int Racket::getHeight()
{
	return height;
}

void Racket::setHeight(int height)
{
	Racket::height = height;
	racket.setSize(sf::Vector2f(width, height));
}

int Racket::getSpeed()
{
	return moveStep;
}

void Racket::setSpeed(int p_speed)
{
	moveStep = p_speed;
}

#pragma endregion

#pragma region FONCTIONS

void Racket::moveUp(bool move, int position)
{
	if (move && posY >= position)
	{
		setPosY(posY - moveStep);
	}
}

void Racket::moveDown(bool move, int position)
{
	if (move && posY <= position)
	{
		setPosY(posY + moveStep);
	}
}

void Racket::autoPilot(int ballPosY, int directionBall, int boardHeight)
{
	int racketCenter = posY + height / 2;
	if (directionBall > 0)
	{
		if (racketCenter > ballPosY )
			setPosY(posY - moveStep);
		else if (racketCenter < ballPosY)
			setPosY(posY + moveStep);
	}
	else
	{
		if (racketCenter > (boardHeight/2) +(height / 2))
			setPosY(posY - moveStep);
		else if (racketCenter < (boardHeight / 2) + (height / 2))
			setPosY(posY + moveStep);
	}

}

sf::RectangleShape Racket::draw()
{
	return racket;
}

#pragma endregion


