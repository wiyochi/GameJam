#pragma once
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;

class Bouton
{
public:
	Bouton(float x, float y, float hauteur, float largeur,string texteBouton, sf::RenderWindow* window);
	~Bouton();
	bool ClicBouton();
	void draw();

private:
	float m_x,m_y, m_hauteur, m_largeur;
	string m_texteBouton;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape rectangle;
	sf::RenderWindow* m_window;
};

	

