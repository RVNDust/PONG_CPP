#include <SFML/Graphics.hpp>
#include <math.h>

namespace pixelisation {
	const int DIM_WIDTH = 800;
	const int DIM_HEIGHT = 600;
	const int DIM_CELL = 32;

	int randomColor()
	{

	}
}

int main()
{
	using namespace pixelisation;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}