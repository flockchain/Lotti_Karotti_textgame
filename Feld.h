#pragma once

using namespace std;

class Feld
{
public:
	Feld();
	~Feld();

	void werdeLoch();
	void belegung(int figur, int spieler);
	void standard();
	int getSpieler();
	int getFigur();
	int getStatus();

private:
	int status;
	int spieler;
	int figur;
};