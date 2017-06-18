#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BitLine
{
public:
	BitLine(sf::RenderWindow* win, float x, float speed, int num, string filePath);
	~BitLine();
	void newBlock(string touche);
	void update();
	void draw();
private:
	int m_num;
	string m_filePath;
	float m_x;
	float m_speed;
	sf::RenderWindow* window;
	vector <int> yPosArray;
	vector <sf::RectangleShape> rectArray;
	sf::RectangleShape drawableLine1;
	sf::RectangleShape drawableLine2;
};

