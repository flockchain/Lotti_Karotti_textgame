#pragma once

using namespace std;

class Spielfigur
{
public:
	Spielfigur();
	~Spielfigur();

	void setNummer(int num);
	void geheFelder(int felder);
	void setFeld(int neu);
	int getFeld();
	int getNummer();

private:
	int nummer;
	int feld;
};