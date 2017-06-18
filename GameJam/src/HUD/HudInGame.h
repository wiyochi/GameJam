#pragma once
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;


class HudInGame
{
public:

	HudInGame( string title, sf::RenderWindow* window);
	~HudInGame();
	void draw();



private:
	int m_score;
	string m_title;
	string m_extremFever;
	sf::RenderWindow* m_window;



};