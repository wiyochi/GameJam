#include "BitLine.h"

BitLine::BitLine(sf::RenderWindow* win, float y, int speed)
{
	window = win;
	m_y = y;
	m_speed = speed;
}


BitLine::~BitLine()
{
}

void BitLine::newBlock(string touche)
{
	rectArray.push_back(sf::RectangleShape(sf::Vector2f(0, m_y)));
	rectArray[rectArray.size() - 1].setSize(sf::Vector2f(50, 0));
}

void BitLine::update()
{
	for (int i = 0; i < rectArray.size(); i++)
	{
		rectArray[i].move()
	}
}

void BitLine::draw()
{
}
