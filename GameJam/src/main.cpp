#include <SFML\Graphics.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"

int main()
{
	const float speed = 1.5f;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works bite!");
	window.setFramerateLimit(500);
	window.setPosition(sf::Vector2i(1000, 0));

	sf::Texture bgTexture;
	bgTexture.loadFromFile("ressources\\HUD\\gameJam-background.jpg");
	bgTexture.setSmooth(true);

	sf::Sprite bg;
	bg.setTexture(bgTexture);
	bg.setPosition({ 0, 0 });

	BitLine lineB(&window, speed, BitLine::LettreB);
	BitLine lineE(&window, speed, BitLine::LettreE);
	BitLine lineF(&window, speed, BitLine::LettreF);
	BitLine lineH(&window, speed, BitLine::LettreH);
	BitLine lineI(&window, speed, BitLine::LettreI);
	BitLine lineL(&window, speed, BitLine::LettreL);
	BitLine lineQ(&window, speed, BitLine::LettreQ);
	BitLine lineU(&window, speed, BitLine::LettreU);
	BitLine lineV(&window, speed, BitLine::LettreV);
	BitLine lineZ(&window, speed, BitLine::LettreZ);
	
	//lineE.hide();
	//lineF.hide();
	//lineH.hide();
	//lineI.hide();
	//lineL.hide();
	//lineQ.hide();
	//lineU.hide();
	//lineV.hide();
	//lineZ.hide();

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
		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			lineQ.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			lineZ.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			lineE.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			lineF.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
			lineV.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			lineB.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			lineH.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			lineU.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			lineI.keyPressed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			lineL.keyPressed();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			lineB.newBlock();
			lineE.newBlock();
			lineF.newBlock();
			lineH.newBlock();
			lineI.newBlock();
			lineL.newBlock();
			lineQ.newBlock();
			lineU.newBlock();
			lineV.newBlock();
			lineZ.newBlock();
		}

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
		window.draw(bg);
		lineL.drawBg();
		lineF.drawBg();
		lineB.drawBg();
		lineE.drawBg();
		lineH.drawBg();
		lineI.drawBg();
		lineQ.drawBg();
		lineU.drawBg();
		lineZ.drawBg();
		lineV.drawBg();

		lineL.draw();
		lineF.draw();
		lineB.draw();
		lineE.draw();
		lineH.draw();
		lineI.draw();
		lineQ.draw();
		lineU.draw();
		lineZ.draw();
		lineV.draw();

		window.display();
	}

	return 0;
}