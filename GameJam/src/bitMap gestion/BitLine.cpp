#include "BitLine.h"

BitLine::BitLine(sf::RenderWindow* win, float x, float speed, int num, string filePath)
{
	window = win;
	m_x = x;
	m_speed = speed;
	m_num = num;
	m_filePath = filePath;
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
	rectArray[rectArray.size() - 1].setPosition(sf::Vector2f(m_x + 1, 0));
	rectArray[rectArray.size() - 1].setSize(sf::Vector2f(50, 50));
	rectArray[rectArray.size() - 1].setFillColor(sf::Color::White);
}

void BitLine::update()
{
	for (unsigned int i = 0; i < rectArray.size(); i++)
	{
		rectArray[i].move(sf::Vector2f(0, 0.2f));
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
