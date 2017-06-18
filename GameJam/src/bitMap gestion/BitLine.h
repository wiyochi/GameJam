#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

class BitLine
{
public:
	BitLine();
	~BitLine();
	void newBlock(string touche);
private:
	int m_num;
	float m_y;
	sf::RenderWindow* window;
	vector <
};

