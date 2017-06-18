#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class BitLine
{
public:
	BitLine(sf::RenderWindow* win, float x, float speed, int num, ifstream* f);
	~BitLine();
	void newBlock(string touche);
	void update();
	void draw();
private:
	int m_num;
	ifstream* m_file;
	float m_x;
	float m_speed;
	sf::RenderWindow* window;
	vector <int> yPosArray;
	vector <sf::RectangleShape> rectArray;
	sf::RectangleShape drawableLine1;
	sf::RectangleShape drawableLine2;
};

