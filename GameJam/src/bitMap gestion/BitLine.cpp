#include "BitLine.h"

BitLine::BitLine(sf::RenderWindow* win, float speed, type t)
{
	window = win;
	m_speed = speed;
	m_type = t;
	endLine = false;
	m_hidden = false;

	float xTmp = 215.f;

	switch (m_type)
	{
	case LettreQ:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreQ.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapQ.txt");
		m_x = xTmp;
		break;
	case LettreZ:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreZ.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapZ.txt");
		m_x = xTmp + 103;
		break;
	case LettreE:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreE.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapE.txt");
		m_x = xTmp + 206;
		break;
	case LettreF:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreF.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapF.txt");
		m_x = xTmp + 309;
		break;
	case LettreV:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreV.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapV.txt");
		m_x = xTmp + 412;
		break;
	case LettreB:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreB.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapB.txt");
		m_x = xTmp + 515;
		break;
	case LettreH:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreH.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapH.txt");
		m_x = xTmp + 618;
		break;
	case LettreU:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreU.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapU.txt");
		m_x = xTmp + 721;
		break;
	case LettreI:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreI.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapI.txt");
		m_x = xTmp + 834;
		break;
	case LettreL:
		m_texture.loadFromFile("ressources\\HUD\\gameJam-LettreL.png");
		m_texture.setSmooth(true);
		m_file = new ifstream("ressources\\bitMap\\bitmapL.txt");
		m_x = xTmp + 937;
		break;
	}

	if (!m_file)
		cout << "Impossible d'ouvrir le fichier" << endl;
	*m_file >> m_compteur;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);

	m_blockTexture.loadFromFile("ressources\\HUD\\beatTiles.png");
	m_blockTexture.setSmooth(true);

	hitY = 900.f;
	hitHeight = 100.f;

	hitRect.setPosition(m_x-20, hitY);
	hitRect.setSize(sf::Vector2f(99.f, hitHeight));
	hitRect.setFillColor(sf::Color(0, 0, 0, 0));
	hitRect.setOutlineThickness(10);
	hitRect.setOutlineColor(sf::Color::Green);
}

BitLine::~BitLine()
{
	delete m_file;
}

void BitLine::newBlock()
{
	sf::Sprite spriteB;
	spriteB.setTexture(m_blockTexture);
	spriteB.setPosition({ 0, 0 });

	blockArray.push_back(spriteB);
	blockArray[blockArray.size() - 1].setPosition(sf::Vector2f(m_x + 1, -50));
}

void BitLine::update()
{
	//On ajoute a la liste de suppression si un carre sort de lecran
	for (unsigned int i = 0; i < blockArray.size(); i++)
	{
		blockArray[i].move(sf::Vector2f(0, m_speed));
		if (blockArray[i].getPosition().y > 2000)
			indexErase.push_back(i);
	}

	//Test dans le hitRect + touche clavier
	for (unsigned int i = 0; i < blockArray.size(); i++)
	{
		bool in = blockArray[i].getPosition().y > hitY && blockArray[i].getPosition().y + 50 < hitY + hitHeight;

		if (m_type == LettreQ && in && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			indexErase.push_back(i);
		if (m_type == LettreZ && in && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			indexErase.push_back(i);
		if (m_type == LettreE && in && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			indexErase.push_back(i);
		if (m_type == LettreF && in && sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			indexErase.push_back(i);
		if (m_type == LettreV && in && sf::Keyboard::isKeyPressed(sf::Keyboard::V))
			indexErase.push_back(i);
		if (m_type == LettreB && in && sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			indexErase.push_back(i);
		if (m_type == LettreH && in && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			indexErase.push_back(i);
		if (m_type == LettreU && in && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			indexErase.push_back(i);
		if (m_type == LettreI && in && sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			indexErase.push_back(i);
		if (m_type == LettreL && in && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			indexErase.push_back(i);
	}

	//On supprime les carre hors ecran et dans le hitRect
	for (unsigned int i = 0; i < indexErase.size(); i++)
	{
		blockArray.erase(blockArray.begin() + indexErase[i]);
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
	if (!m_hidden)
	{
		for (unsigned int i = 0; i < blockArray.size(); i++)
		{
			window->draw(blockArray[i]);
		}
	}
}

void BitLine::drawBg()
{
	if (!m_hidden)
	{
		window->draw(m_sprite);
		window->draw(hitRect);
	}
}

bool BitLine::isHidden() const
{
	return m_hidden;
}

void BitLine::show()
{
	m_hidden = false;
}

void BitLine::hide()
{
	m_hidden = true;
}
