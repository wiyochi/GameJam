#pragma once
#include <string>

using namespace std;

class Bouton
{
public:
	Bouton();
	~Bouton();
	bool ClicBouton();


private:
	int x, y, heuteur, largeur;
	string texteBouton;
};

	

