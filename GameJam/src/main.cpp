#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works bite!");
	window.setFramerateLimit(500);

	ifstream fileI("ressources\\bitMap\\bitmap.txt");

	BitLine lineTest(&window, 50.f, 0.8f, 1, &fileI);

	//ofstream fileO("ressources\\bitMap\\bitmap.txt");

	//Writer testWrite(&fileO);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased)
			{
				//if (event.key.code == sf::Keyboard::Space)
				//	testWrite.reset();
			}
		}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && testWrite.isReleasedState())
		//	testWrite.nextIs();

		lineTest.update();

		window.clear();

		//testWrite.write();
		lineTest.draw();

		window.display();
	}

	return 0;
}