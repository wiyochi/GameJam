#include "Bouton.h"



Bouton::Bouton(float x, float y, float hauteur, float largeur,string texteBouton, sf::RenderWindow* window)
{
	m_x = x;
	m_y = y;
	m_hauteur = hauteur;
	m_largeur = largeur;
	m_texteBouton = texteBouton;
	rectangle.setSize(sf::Vector2f(m_largeur, m_hauteur));
	rectangle.setPosition(sf::Vector2f(m_x, m_y));
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color(142, 14, 0, 255));

	text.setPosition(sf::Vector2f(m_x+150, m_y+15));
	font.loadFromFile("ressources\\HUD\\Bauhaus-93_6274.ttf");
	text.setFont(font);
	text.setString(m_texteBouton);
	text.setFillColor(sf::Color(142, 14, 0, 255));
	text.setCharacterSize(50);

	m_window = window;
}


Bouton::~Bouton()
{
}

bool Bouton::ClicBouton()
{
	return false;
}

void Bouton::draw()
{
	m_window->draw(rectangle);
	m_window->draw(text);
}
