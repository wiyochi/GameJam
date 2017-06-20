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
	void extremFeverUptade();
	void extremFeverDraw();
	void scoreUptade();
	void raiseScore();
	void resetScore();
	void keyReleased();
	void animationScoreUptade();

private:
	int m_score;
	string m_title;
	string m_extremFever;
	sf::RenderWindow* m_window;
	sf::Font m_font;
	sf::Text m_textTitle;
	sf::Text m_textFever;
	sf::Text m_textScore;
	sf::Vector2f m_originTextExtremFever;
	bool ifLimitScaleFever;
	sf::Vector2f limitScaleFever;
	sf::Event m_event;
	bool isKeyPressed;
	bool ifLimitScaleScore;
	sf::Vector2f limitScaleScore;
	bool animationScore;


	sf::Texture bgTexture;
	sf::Sprite bg;
};