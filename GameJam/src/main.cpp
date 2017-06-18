#include <SFML\Graphics.hpp>
#include "HUD\HudInGame.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	window.setFramerateLimit(500);
	HudInGame test("french core", &window);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyReleased)
			{
				
				if (event.key.code == sf::Keyboard::F)
				{
					test.keyReleased();
				}
			}
			
		}
		test.extremFeverUptade();
		test.scoreUptade();
		window.clear();
		test.draw();
		test.extremFeverDraw();
		window.display();
		sf::sleep(sf::milliseconds(50));
	}

	return 0;
}



