#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works bite!");
	window.setFramerateLimit(500);

	sf::Texture background;
	if(background.loadFromFile("ressources\\HUD\\gameJam-background.jpg", sf::IntRect(0, 0, 1920, 1080)))
		cout << "yolo" << endl;

	background.setSmooth(true);
	sf::Sprite spriteBg;
	spriteBg.setTexture(background);
	spriteBg.setScale({ 1, 1 });
	

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
		// ici on fous les draws !

		testWrite.write();
		window.draw(spriteBg);
		lineTest.draw();

		window.display();
	}

	return 0;
}