#pragma once
#include "Feld.h"
#include "Spielkarte.h"
#include "Spieler.h"
#include <vector>

using namespace std;

class Spielfeld
{
public:
	Spielfeld();
	~Spielfeld();
	void initStapel();
	void feldAusgabe();
	void figurBewegen(int num, int p, int s);
	void dreheKarotte();
	void setWinner();
	int karteZiehen(int karte);
	int checkFeld(Feld feld);
	int getWinningPlayer();
	bool getWinner();

	vector<Feld> felder;
	vector<Spielkarte> stapel;
	vector<Spieler> players;

private:
	int winner;
	bool winning = false;
};