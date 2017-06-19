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
	typedef enum
	{
		LettreB,
		LettreE,
		LettreF,
		LettreH,
		LettreI,
		LettreL,
		LettreQ,
		LettreU,
		LettreV,
		LettreZ,
	} type;
	BitLine(sf::RenderWindow* win, float speed, type t);
	~BitLine();
	void newBlock();
	void update();
	void draw();
	void drawBg();
	bool isHidden() const;
	void show();
	void hide();
private:
	type m_type;
	ifstream* m_file;
	int m_compteur;
	float m_x;
	float m_speed;
	bool endLine;
	bool m_hidden;
	sf::RenderWindow* window;
	vector <int> yPosArray;
	vector <sf::RectangleShape> rectArray;
	vector <int> indexErase;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Texture m_blockTexture;
	vector <sf::Sprite> blockArray;

	sf::RectangleShape hitRect;
	float hitY;
	float hitHeight;
};

