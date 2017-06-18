#include "BitLine.h"

BitLine::BitLine(sf::RenderWindow* win, float x, float speed, int num, ifstream* f)
{
	window = win;
	m_x = x;
	m_speed = speed;
	m_num = num;
	endLine = false;
	m_file = f;

	if (!m_file)
		cout << "Impossible d'ouvrir le fichier" << endl;
	*m_file >> m_compteur;

	drawableLine1.setPosition(sf::Vector2f(m_x, 0));
	drawableLine1.setSize(sf::Vector2f(1, window->getSize().y));
	drawableLine1.setFillColor(sf::Color::White);
	drawableLine2.setPosition(sf::Vector2f(m_x + 51, 0));
	drawableLine2.setSize(sf::Vector2f(1, window->getSize().y));
	drawableLine2.setFillColor(sf::Color::White);
}

BitLine::~BitLine()
{
}

void BitLine::newBlock(string touche)
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
	}

	if (!endLine)
	{
		if (m_compteur > 0)
		{
			m_compteur--;
		}
		else
		{
			newBlock("touche");

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
}
