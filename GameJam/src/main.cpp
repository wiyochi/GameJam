#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");

	ifstream fileI("ressources\\bitMap\\bitmap.txt");

	BitLine lineTest(&window, 50.f, 0.2f, 1, &fileI);
	lineTest.newBlock("a");

	ofstream fileO("ressources\\bitMap\\bitmap.txt");

	Writer testWrite(&fileO);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			testWrite.nextIs();

		lineTest.update();

		window.clear();

		testWrite.write();
		lineTest.draw();

		window.display();
	}

	return 0;
}