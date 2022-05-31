#pragma once
#include <string>
#include <vector>
#include "Spielfigur.h"

using namespace std;

class Spieler
{
public:
	Spieler();
	~Spieler();

	void initFigures();
	void setName(string name);
	void setFarbe(string farbe);
	string getName();
	string getFarbe();

	vector<Spielfigur> figures;
private:
	string name;
	string farbe;		
};