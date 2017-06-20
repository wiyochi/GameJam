#include "HudInGame.h"

HudInGame::HudInGame( string title, sf::RenderWindow* window)
{
	m_score = 0;
	m_title = title;
	m_extremFever = "EXTREM FEVER !";
	m_window = window;
	ifLimitScaleFever = false;
	isKeyPressed = false;
	ifLimitScaleScore = false;
	limitScaleFever = m_textFever.getScale();
	limitScaleScore = m_textFever.getScale();

	m_font.loadFromFile("ressources\\HUD\\Bauhaus-93_6274.ttf");
	m_textTitle.setFont(m_font);
	m_textTitle.setString(m_title);
	m_textTitle.setCharacterSize(70);
	m_textTitle.setFillColor(sf::Color::White);
	m_textTitle.setPosition(sf::Vector2f(170, 50));

	m_textFever.setFont(m_font);
	m_textFever.setString(m_extremFever);
	m_textFever.setCharacterSize(30);
	m_textFever.setFillColor(sf::Color(142,14,0,255));
	m_textFever.setPosition(1600, 900);
	m_textFever.setScale(1, 1);

	m_textScore.setFont(m_font);
	m_textScore.setString(to_string(m_score));
	m_textScore.setCharacterSize(70);
	m_textScore.setFillColor(sf::Color::White);
	m_textScore.setPosition(sf::Vector2f(1750, 235));
	m_textScore.setScale(1, 1);

	m_originTextExtremFever = m_textFever.getOrigin();
	m_textFever.setOrigin(sf::Vector2f(m_originTextExtremFever.x + 105, m_originTextExtremFever.y+20));

	bgTexture.loadFromFile("ressources\\HUD\\gameJam-background.jpg");
	bgTexture.setSmooth(true);

	bg.setTexture(bgTexture);
	bg.setPosition({ 0, 0 });
}

HudInGame::~HudInGame()
{
}

void HudInGame::draw()
{
	m_window->draw(bg);
	m_window->draw(m_textTitle);
	m_window->draw(m_textScore);
}

void HudInGame::extremFeverUptade()
{
	limitScaleFever = m_textFever.getScale();
	
	if (ifLimitScaleFever == false)
	{
		m_textFever.scale(1.04f, 1.04f);
	}
	else 
	{
		m_textFever.scale(0.9f, 0.9f);
	}
	
	if(limitScaleFever.x>1 || limitScaleFever.y>1)
	{
		ifLimitScaleFever = true;
	}
	
	else if(limitScaleFever.x < 0.7 || limitScaleFever.y < 0.7)
	{
		ifLimitScaleFever = false;
	}
	m_textFever.rotate(2);
}

void HudInGame::extremFeverDraw()
{
	if (m_score > 10)
		m_window->draw(m_textFever);
}

void HudInGame::scoreUptade()
{
	if (animationScore)
	{
		animationScoreUptade();
	}
}

void HudInGame::raiseScore()
{
	if (!isKeyPressed)
	{
		m_score = m_score + 10;
		m_textScore.setString(to_string(m_score));
		isKeyPressed = true;
		animationScore = true;
	}
}

void HudInGame::resetScore()
{
	m_score = 0;
	animationScore = true;
}

void HudInGame::keyReleased()
{
	isKeyPressed = false;
}

void HudInGame::animationScoreUptade()
{
	limitScaleScore = m_textScore.getScale();

	if (ifLimitScaleScore == false)
	{
		m_textScore.scale(1.1f, 1.1f);
	}
	else
	{
		m_textScore.scale(0.9f, 0.9f);
	}

	if (limitScaleScore.x>1.5 || limitScaleScore.y>1.5)
	{
		ifLimitScaleScore = true;
	}

	else if (limitScaleScore.x < 1 || limitScaleScore.y < 1)
	{
		ifLimitScaleScore = false;
		
		m_textScore.setScale(1, 1);
		animationScore = false;
	}
}

