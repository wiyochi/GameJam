#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works bite!");
	window.setFramerateLimit(500);
	window.setPosition(sf::Vector2i(950, 0));

	BitLine lineB(&window, 50.f, 0.8f, BitLine::LettreB);
	BitLine lineE(&window, 50.f, 0.8f, BitLine::LettreE);
	BitLine lineF(&window, 50.f, 0.8f, BitLine::LettreF);
	BitLine lineH(&window, 50.f, 0.8f, BitLine::LettreH);
	BitLine lineI(&window, 50.f, 0.8f, BitLine::LettreI);
	BitLine lineL(&window, 50.f, 0.8f, BitLine::LettreL);
	BitLine lineQ(&window, 50.f, 0.8f, BitLine::LettreQ);
	BitLine lineU(&window, 50.f, 0.8f, BitLine::LettreU);
	BitLine lineV(&window, 50.f, 0.8f, BitLine::LettreV);
	BitLine lineZ(&window, 50.f, 0.8f, BitLine::LettreZ);

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

		lineB.update();
		lineE.update();
		lineF.update();
		lineH.update();
		lineI.update();
		lineL.update();
		lineQ.update();
		lineU.update();
		lineV.update();
		lineZ.update();

		window.clear();

		//testWrite.write();
		lineB.draw();
		lineE.draw();
		lineF.draw();
		lineH.draw();
		lineI.draw();
		lineL.draw();
		lineQ.draw();
		lineU.draw();
		lineV.draw();
		lineZ.draw();

		window.display();
	}

	return 0;
}