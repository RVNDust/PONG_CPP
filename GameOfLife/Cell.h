#ifndef DEF_GAMEOFLIFE
#define DEF_GAMEOFLIFE

#include <SFML\Graphics.hpp>

class GameOfLife //: public sf::Drawable, public sf::Transformable
{
public:
	GameOfLife();
	~GameOfLife();

	sf::VertexArray createCell(float posX, float posY, float dim);
	void drawGameBoard(sf::RenderWindow &window);

private:
	sf::VertexArray gameBoard[32][32];
	int posX = 200; int posY = 200; //Position initiale du coin supérieur gauche au sein de la fenêtre
	int width = 320; int height = 320; //Largeur et hauteur du tableau contenant les cellules
	int cellSize = 10; //Taille en pixel des cellules
};



#endif // !DEF_GAMEOFLIFE
