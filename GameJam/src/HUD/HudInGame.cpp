#include "HudInGame.h"

HudInGame::HudInGame( string title, sf::RenderWindow* window)
{
	m_score = 0;
	m_title = title;
	m_extremFever = "EXTREM FEVER !";
	m_window = window;
}

HudInGame::~HudInGame()
{
}

void HudInGame::draw()
{

}
