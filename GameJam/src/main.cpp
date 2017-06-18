#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
	BitLine lineTest(&window, 50.f, 0.2f, 1, "ressources\\bitMap\\bitmap.txt");
	lineTest.newBlock("a");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		lineTest.update();

		window.clear();

		lineTest.draw();

		window.display();
	}

	return 0;
}