#include "BitLine.h"

BitLine::BitLine(sf::RenderWindow* win, float x, float speed, type t)
{
	window = win;
	m_x = x;
	m_speed = speed;
	m_type = t;
	endLine = false;

	drawableLine1.setPosition(sf::Vector2f(m_x, 0));
	drawableLine1.setSize(sf::Vector2f(1, window->getSize().y));
	drawableLine1.setFillColor(sf::Color::White);
	drawableLine2.setPosition(sf::Vector2f(m_x + 51, 0));
	drawableLine2.setSize(sf::Vector2f(1, window->getSize().y));
	drawableLine2.setFillColor(sf::Color::White);

	switch (m_type)
	{
	case LettreB:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreB.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapB.txt");
		break;
	case LettreE:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreE.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapE.txt");
		break;
	case LettreF:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreF.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapF.txt");
		break;
	case LettreH:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreH.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapH.txt");
		break;
	case LettreI:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreI.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapI.txt");
		break;
	case LettreL:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreL.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapL.txt");
		break;
	case LettreQ:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreQ.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapQ.txt");
		break;
	case LettreU:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreU.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapU.txt");
		break;
	case LettreV:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreV.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapV.txt");
		break;
	case LettreZ:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreZ.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapZ.txt");
		break;
	}

	if (!m_file)
		cout << "Impossible d'ouvrir le fichier" << endl;
	*m_file >> m_compteur;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
}

BitLine::~BitLine()
{
	delete m_file;
}

void BitLine::newBlock()
{
	rectArray.push_back(sf::RectangleShape());
	rectArray[rectArray.size() - 1].setPosition(sf::Vector2f(m_x + 1, -50));
	rectArray[rectArray.size() - 1].setSize(sf::Vector2f(50, 50));
	rectArray[rectArray.size() - 1].setFillColor(sf::Color::White);
}

void BitLine::update()
{
	for (unsigned int i = 0; i < rectArray.size(); i++)
	{
		rectArray[i].move(sf::Vector2f(0, m_speed));
		if (rectArray[i].getPosition().y > window->getSize().y-400)
			indexErase.push_back(i);
	}

	for (unsigned int i = 0; i < indexErase.size(); i++)
	{
		rectArray.erase(rectArray.begin() + indexErase[i]);
	}
	indexErase.clear();

	if (!endLine)
	{
		if (m_compteur > 0)
		{
			m_compteur--;
		}
		else
		{
			newBlock();

			string str;
			*m_file >> str;
			if (str != ";")
				m_compteur = stoi(str);
			else
				endLine = true;
		}
	}

}

void BitLine::draw()
{
	window->draw(drawableLine1);
	for (unsigned int i = 0; i < rectArray.size(); i++)
	{
		window->draw(rectArray[i]);
	}
	window->draw(drawableLine2);
	window->draw(m_sprite);
}