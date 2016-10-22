#include "Board.h"

Board::Board()
{
	posX = 100;  posY = 100;
	height = 600;  width = 800;

	board.setPosition(posX, posY);
	board.setSize(sf::Vector2f(width, height));
	board.setFillColor(sf::Color::Transparent);
	board.setOutlineThickness(5);
	board.setOutlineColor(sf::Color::White);
}


#pragma region ACCESSEUR / MUTATEURS

int Board::getPosX()
{
	return posX;
}

void Board::setPosX(int x)
{
	posX = x;
	board.setPosition(posX, posY);
}

int Board::getPosY()
{
	return posY;
}

void Board::setPosY(int y)
{
	posY = y;
	board.setPosition(posX, posY);
}

int Board::getWidth()
{
	return width;
}

void Board::setWidth(int width)
{
	Board::width = width;
	board.setSize(sf::Vector2f(width, height));
}

int Board::getHeight()
{
	return height;
}

void Board::setHeight(int height)
{
	Board::height = height;
	board.setSize(sf::Vector2f(width, height));
}

#pragma endregion

#pragma region FONCTIONS

sf::RectangleShape Board::draw()
{
	return board;
}

#pragma endregion


