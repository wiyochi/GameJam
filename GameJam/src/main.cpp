#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "bitMap gestion\BitLine.h"
#include "bitMap gestion\Writer.h"
#include "HUD\HudInGame.h"

int main()
{
	const float speed = 1.7f;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works bite!");
	window.setFramerateLimit(500);
	window.setPosition(sf::Vector2i(1000, 0));

	sf::Music espera;
	espera.openFromFile("ressources\\music\\EMROD - Espera.wav");
	espera.play();
	espera.setVolume(50);

	HudInGame hud("EMROD - Espera", &window);

	BitLine lineB(&window, speed, BitLine::LettreQ, &hud);
	BitLine lineH(&window, speed, BitLine::LettreZ, &hud);
	BitLine lineE(&window, speed, BitLine::LettreE, &hud);
	BitLine lineF(&window, speed, BitLine::LettreF, &hud);
	BitLine lineI(&window, speed, BitLine::LettreV, &hud);
	BitLine lineL(&window, speed, BitLine::LettreB, &hud);
	BitLine lineQ(&window, speed, BitLine::LettreH, &hud);
	BitLine lineU(&window, speed, BitLine::LettreU, &hud);
	BitLine lineV(&window, speed, BitLine::LettreI, &hud);
	BitLine lineZ(&window, speed, BitLine::LettreL, &hud);
	
	//lineE.hide();
	//lineF.hide();
	//lineH.hide();
	//lineI.hide();
	//lineL.hide();
	//lineQ.hide();
	//lineU.hide();
	//lineV.hide();
	//lineZ.hide();

	//ofstream fileQ("ressources\\bitMap\\bitmapQ.txt");
	//ofstream fileZ("ressources\\bitMap\\bitmapZ.txt");
	//ofstream fileE("ressources\\bitMap\\bitmapE.txt");
	//ofstream fileF("ressources\\bitMap\\bitmapF.txt");
	//ofstream fileV("ressources\\bitMap\\bitmapV.txt");
	//ofstream fileB("ressources\\bitMap\\bitmapB.txt");
	//ofstream fileH("ressources\\bitMap\\bitmapH.txt");
	//ofstream fileU("ressources\\bitMap\\bitmapU.txt");
	//ofstream fileI("ressources\\bitMap\\bitmapI.txt");
	//ofstream fileL("ressources\\bitMap\\bitmapL.txt");

	//Writer writeQ(&fileQ);
	//Writer writeZ(&fileZ);
	//Writer writeE(&fileE);
	//Writer writeF(&fileF);
	//Writer writeV(&fileV);
	//Writer writeB(&fileB);
	//Writer writeH(&fileH);
	//Writer writeU(&fileU);
	//Writer writeI(&fileI);
	//Writer writeL(&fileL);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//Reset des writer (a supprimer)
			if (event.type == sf::Event::KeyReleased)
			{
				//if (event.key.code == sf::Keyboard::Q)
				//	writeQ.reset();
				//if (event.key.code == sf::Keyboard::Z)
				//	writeZ.reset();
				//if (event.key.code == sf::Keyboard::E)
				//	writeE.reset();
				//if (event.key.code == sf::Keyboard::F)
				//	writeF.reset();
				//if (event.key.code == sf::Keyboard::V)
				//	writeV.reset();
				//if (event.key.code == sf::Keyboard::B)
				//	writeB.reset();
				//if (event.key.code == sf::Keyboard::H)
				//	writeH.reset();
				//if (event.key.code == sf::Keyboard::U)
				//	writeU.reset();
				//if (event.key.code == sf::Keyboard::I)
				//	writeI.reset();
				//if (event.key.code == sf::Keyboard::L)
				//	writeL.reset();
			}
		}

		//Writer update (a supprimer)
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && writeQ.isReleasedState())
		//	writeQ.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && writeZ.isReleasedState())
		//	writeZ.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && writeE.isReleasedState())
		//	writeE.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && writeF.isReleasedState())
		//	writeF.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && writeV.isReleasedState())
		//	writeV.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && writeB.isReleasedState())
		//	writeB.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && writeH.isReleasedState())
		//	writeH.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && writeU.isReleasedState())
		//	writeU.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && writeI.isReleasedState())
		//	writeI.nextIs();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && writeL.isReleasedState())
		//	writeL.nextIs();




		//Reperage des placements d'objets
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			cout << sf::Mouse::getPosition(window).x << " , " << sf::Mouse::getPosition(window).y << endl;

		//A supprimer
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

		//All updates
		hud.extremFeverUptade();
		hud.scoreUptade();
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

		//Writer
		//writeQ.write();
		//writeZ.write();
		//writeE.write();
		//writeF.write();
		//writeV.write();
		//writeB.write();
		//writeH.write();
		//writeU.write();
		//writeI.write();
		//writeL.write();

		//All draw
		hud.draw();
		hud.extremFeverDraw();
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

	//writeQ.end();
	//writeZ.end();
	//writeE.end();
	//writeF.end();
	//writeV.end();
	//writeB.end();
	//writeH.end();
	//writeU.end();
	//writeI.end();
	//writeL.end();

	return 0;
}