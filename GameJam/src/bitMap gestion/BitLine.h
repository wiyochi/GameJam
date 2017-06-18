#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

class BitLine
{
public:
	BitLine(sf::RenderWindow* win, float y, int speed);
	~BitLine();
	void newBlock(string touche);
	void update();
	void draw();
private:
	int m_num;
	float m_y;
	int m_speed;
	sf::RenderWindow* window;
	vector <int> xPosArray;
	vector <sf::RectangleShape> rectArray;
};

