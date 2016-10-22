#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Board.h"
#include "Racket.h"
#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 750), "PONG");
	window.setFramerateLimit(30);

	sf::Font font; sf::Font scoreFont;
	font.loadFromFile("CODE_Bold.otf");
	scoreFont.loadFromFile("DS-DIGI.TTF");
	sf::Text title; sf::Text scoreA; sf::Text scoreB; sf::Text pause; sf::Text hint; sf::Text win;
	sf::Texture textRacketPlayer; sf::Texture textRacketIA;
	float posX = 100; float posY = 100;
	float height = 600; float width = 800;

	//SOUND
	sf::SoundBuffer pingWall, pingRacket;
	pingWall.loadFromFile("pingMur.ogg");
	pingRacket.loadFromFile("pingRaquette.ogg");
	sf::Sound wallSound, racketSound;
	wallSound.setBuffer(pingWall);
	racketSound.setBuffer(pingRacket);

#pragma region TEXTS
	int scoreJoueur = 0;
	int scoreIA = 0;

	title.setFont(font);
	scoreA.setFont(scoreFont);
	scoreB.setFont(scoreFont);
	pause.setFont(font);
	hint.setFont(font);
	win.setFont(font);

	title.setString("PONG REVISITED");
	scoreA.setString(std::to_string(scoreJoueur));
	scoreB.setString(std::to_string(scoreIA));
	pause.setString("PAUSE");
	hint.setString("TAP SPACE TO START");

	title.setCharacterSize(24);
	scoreA.setCharacterSize(40);
	scoreB.setCharacterSize(40);
	pause.setCharacterSize(40);
	hint.setCharacterSize(25);
	win.setCharacterSize(15);

	title.setPosition((window.getSize().x/2) - title.getLocalBounds().width/2, 25);

	title.setColor(sf::Color::Red);
	scoreA.setColor(sf::Color::Red);
	scoreB.setColor(sf::Color::Red);
	pause.setColor(sf::Color::Red);
	hint.setColor(sf::Color::Red);

#pragma endregion

Board board;
int widthPoint = 4; int heightPoint = 10; int offsetPoint = 5;
int countPoint = 0; int pointPosX = board.getPosX() + (board.getWidth() / 2) - (widthPoint / 2); int pointPosY = board.getPosY();
int nbPoints = (board.getHeight() / (heightPoint + offsetPoint)) * 4;
sf::VertexArray middleBoardLine(sf::Quads, nbPoints);

scoreA.setPosition(board.getPosX() + (board.getWidth() / 2) - scoreA.getLocalBounds().width - 10, posY + 10);
scoreB.setPosition(board.getPosX() + (board.getWidth() / 2) + 10, posY + 10);
pause.setPosition(board.getPosX() + (board.getWidth() / 2) - pause.getLocalBounds().width / 2, board.getPosY() + (board.getHeight() / 2) - 30);
hint.setPosition(board.getPosX() + (board.getWidth() / 2) - hint.getLocalBounds().width / 2, board.getPosY() + (board.getHeight() / 2) + 15);

for (int i = 0; i < middleBoardLine.getVertexCount(); i++)
{
	middleBoardLine[i].color = sf::Color::White;
	switch (countPoint)
	{
		case 0:
			middleBoardLine[i].position = sf::Vector2f(pointPosX, pointPosY);
			countPoint++;
			break;
		case 1:
			middleBoardLine[i].position = sf::Vector2f(pointPosX + widthPoint, pointPosY);
			countPoint++;
			break;
		case 2:
			middleBoardLine[i].position = sf::Vector2f(pointPosX + widthPoint, pointPosY + heightPoint);
			countPoint++;
			break;
		case 3:
			middleBoardLine[i].position = sf::Vector2f(pointPosX, pointPosY + heightPoint);
			countPoint = 0;
			pointPosY += heightPoint + offsetPoint;
			break;
	}
}

#pragma region RACKETS
//Racket racketPlayer("raquetteJoueurSmall.png"); Racket racketIA("raquetteIASmall.png");
Racket racketPlayer; Racket racketIA;
racketPlayer.setPosX(board.getPosX() + 10);
racketPlayer.setPosY(board.getPosY() + board.getHeight() / 2);
racketIA.setPosX(board.getPosX() + board.getWidth() - (racketIA.getWidth() + 10));
racketIA.setPosY(board.getPosY() + board.getHeight() / 2);
racketIA.setSpeed(10);
#pragma endregion

#pragma region BALL

Ball ball;
ball.setPosX(board.getPosX() + board.getWidth()/2);
ball.setPosY(board.getPosY() + board.getHeight()/2);
ball.setHeight(10); ball.setWidth(10);

#pragma endregion

bool moveUp = false;
bool moveDown = false;
bool moveUpIA = false;
bool moveDownIA = false;

bool gameInProgress = false;
bool gameEnd = false;
bool scored = false;
bool autoIA = true;
std::string starter = "player"; //  Désigne le joueur qui engage

sf::Clock clock; // démarre le chrono

while (window.isOpen())
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Z:
				moveUp = true;
				break;
			case sf::Keyboard::S:
				moveDown = true;
				break;
			case sf::Keyboard::Up:
				moveUpIA = true;
				break;
			case sf::Keyboard::Down:
				moveDownIA = true;
				break;
			case sf::Keyboard::Space:
				if (gameInProgress && scored && !gameEnd)
				{
					scored = false;
					if (starter == "player")
						ball.initBall(&racketPlayer, true);
					else if (starter == "ia")
						ball.initBall(&racketIA, false);

					starter = "";
				}
				break;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Z:
				moveUp = false;
				break;
			case sf::Keyboard::S:
				moveDown = false;
				break;
			case sf::Keyboard::Up:
				moveUpIA = false;
				break;
			case sf::Keyboard::Down:
				moveDownIA = false;
				break;
			case sf::Keyboard::Space:
				if (!gameInProgress)
				{
					gameInProgress = true;
					ball.initBall(&racketPlayer, true);
					starter = "";
				}
				else if (gameEnd)
				{
					scored = false;
					starter = "player";
					gameInProgress = false;
					gameEnd = false;
				}
			}
		}
	}

	//Mouvements de la raquette du joueur
	racketPlayer.moveUp(moveUp, board.getPosY());
	racketPlayer.moveDown(moveDown, board.getPosY() + board.getHeight() - racketPlayer.getHeight());

	//Mouvements de la raquette de l'IA
	if (!autoIA)
	{
		racketIA.moveUp(moveUpIA, board.getPosY());
		racketIA.moveDown(moveDownIA, board.getPosY() + board.getHeight() - racketIA.getHeight());
	}
	else
	{
		racketIA.autoPilot(ball.getPosY(), ball.getMoveX(), board.getPosX() + board.getHeight());
	}

	if (gameInProgress && !scored)
	{
		//Rebonds sur le bord gauche et droit et compte des points
		scored = ball.isScored(board.getPosX(), board.getPosX() + board.getWidth(), &starter);
		if (starter == "player" && scored && gameInProgress)
		{
			scoreJoueur++;
			scoreA.setString(std::to_string(scoreJoueur));
		}
		else if (starter == "ia" && scored && gameInProgress)
		{
			scoreIA++;
			scoreB.setString(std::to_string(scoreIA));
		}

		//Rebond contre une raquette
		if (ball.isNewDrection(racketPlayer.getPosY(), racketIA.getPosY(), racketPlayer.getPosX(), racketIA.getPosX(), racketPlayer.getWidth(), racketPlayer.getHeight()))
			racketSound.play();

		//Rebonds sur le bord inférieur/supérieur
		if (ball.isOutBoard(board.getPosY(), board.getPosY() + board.getHeight()))
			wallSound.play();

		//Mouvement de la balle
		ball.move();

	}

	if (clock.getElapsedTime().asMilliseconds() >= 2000) {
		ball.speedUp();
		clock.restart();
	}
	if (scoreJoueur >= 10 || scoreIA >= 10)
	{
		if (scoreJoueur >= 10)
		{
			win.setString("Le joueur de gauche a gagné !");
		}
		else if (scoreIA >= 10)
		{
			win.setString("Le joueur de droite a gagné !");
		}
		win.setPosition((window.getSize().x / 2) - win.getLocalBounds().width / 2, (window.getSize().y / 2) - 30);
		gameEnd = true;
		scoreA.setString("0"); scoreB.setString("0");
	}

		window.clear();
		window.draw(title);
		window.draw(board.draw());
		window.draw(middleBoardLine);
		window.draw(scoreA);
		window.draw(scoreB);
		window.draw(racketPlayer.draw());
		window.draw(racketIA.draw());
		if (gameInProgress && !scored && !gameEnd)
			window.draw(ball.draw());
		else if (gameInProgress && scored && !gameEnd)
		{
			window.draw(pause);
		}
		else if (!gameInProgress && !gameEnd)
		{
			window.draw(pause);
			window.draw(hint);
		}
		else if (gameEnd)
		{
			window.draw(win);
		}
		window.display();
	}

	return 0;
}