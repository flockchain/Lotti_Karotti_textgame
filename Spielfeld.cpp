#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "Spielfeld.h"
#include "Feld.h"
#include "Spielkarte.h"
#include "Spieler.h"

using namespace std;

Spielfeld::Spielfeld()
{
	this->winner = 0;
	this->winning = false;
	this->felder.resize(27);
	//Felder inintialisierung
	for (int i = 0; i <= 26; i++)
	{
		this->felder.push_back(Feld());
		this->felder[i].standard();
	}
	
	//Spielkarten initialisierung
	this->initStapel();

	//Spieler initialisierung
	int p;
	cout << "Wieviele Personen moechten an dem Spiel teilnehmen? 2-4 Spieler: ";
	cin >> p;
	if (p != 2 && p != 3 && p != 4)
	{
		do
		{
			cout << "\nSie haben eine ungueltige Zahl eingegeben, bitte waehlen sie ihre Spieleranzahl. 2 - 4 Spieler: ";
			cin >> p;
		} while (p != 2 && p != 3 && p != 4);
	}
	cout << "\n\n";

	string name;
	string farbe;
	for (int i = 0; i <= p-1; i++)
	{
		cout << "\nPlayer " << i+1 << " enter your name: ";
		cin >> name;

		cout << "\nAnd your color: ";
		cin >> farbe;

		players.push_back(Spieler());
		players.resize(p + 1);
		this->players[i].setName(name);
		this->players[i].setFarbe(farbe);
		this->players[i].initFigures();
	}

	cout << "Board was initialized" << endl;
}

Spielfeld::~Spielfeld()
{

}

void Spielfeld::initStapel()
{
	for (int i = 0; i <= 99; i++)
	{
		this->stapel.push_back(Spielkarte());
	}
	this->stapel.resize(100);
	for (int i = 0; i <= 24; i++)
	{
		this->stapel[i].setBild(1);
	}

	for (int i = 25; i <= 49; i++)
	{
		this->stapel[i].setBild(2);
	}

	for (int i = 50; i <= 74; i++)
	{
		this->stapel[i].setBild(3);
	}

	for (int i = 75; i <= 99; i++)
	{
		this->stapel[i].setBild(4);
	}

	//Spielkarten mischen
	random_device rd;
	default_random_engine rng(rd());
	shuffle(this->stapel.begin(), this->stapel.end(), rng);
}

void Spielfeld::feldAusgabe()
{
	this->felder.resize(27);
	for (int i = 1; i <= 26; i++)
	{
		if (this->felder[i].getStatus() == 1)
		{
			cout << "O  ";
		}

		else if (this->felder[i].getStatus() == 0)
		{
			cout << "( )  ";
		}

		else if (this->felder[i].getStatus() == 2)
		{
			cout << "( Spieler: " << this->felder[i].getSpieler()+1 << " , Figur: " << this->felder[i].getFigur()+1 << " ) ";
		}
	}
}

int Spielfeld::karteZiehen(int karte)
{
	this->stapel.resize(100);
	int k = this->stapel[karte].getBild();
	if(k == 1)
	{
		this->stapel.pop_back();
		return 1;
	}
	else if (k == 2)
	{
		this->stapel.pop_back();
		return 2;
	}
	else if (k == 3)
	{
		this->stapel.pop_back();
		return 3;
	}
	else if (k == 4)
	{
		this->stapel.pop_back();
		return 4;
	}
	this->stapel.pop_back();
	return 0;
}

void Spielfeld::figurBewegen(int num, int p, int s)
{
	//permit access to the vectores
	this->players.resize(s);
	this->players[p].figures.resize(4);

	//initalize local variables
	int field, figure, oldField;

	cout << "\nWhich of your 4 figures do you want to move " << num << " field: ";
	cin >> figure;
	figure -= 1;

	field = this->players[p].figures[figure].getFeld() + num;
	
	//Check if the destinated field is free until all figures have been tried
		//destinated field is free
		if (this->checkFeld(this->felder[field]) == 1)
		{
			//Save old field
			oldField = this->players[p].figures[figure].getFeld();
			//walk the fields
			this->players[p].figures[figure].geheFelder(num);
			this->felder[field].belegung(figure, p);
			this->players[p].figures[figure].setFeld(field);
			//Set old field free
			if (field != oldField)
			{
				this->felder[oldField].standard();
				cout << "Player " << p + 1 << " is walked " << num << " field/s with his figure number " << figure + 1 << "\n\n";
			}
			if (field == 26)
			{
				this->winning = true;
				this->winner = p + 1;
			}
		}
		//destinated field is occupied
		else if(this->checkFeld(this->felder[field]) == 2)
		{
			for (int i = 0; i <= 2; i++)
			{
				cout << "You can't move this figure, please choose another one, which of your figures do you want to move: ";
				cin >> figure;
				if (this->checkFeld(this->felder[field]) == 1)
				{
					//Save old field
					oldField = this->players[p].figures[figure].getFeld();
					//walk the fields
					this->players[p].figures[figure].geheFelder(num);
					this->felder[field].belegung(figure, p);
					this->players[p].figures[figure].setFeld(field);
					//Set old field free
					if (field != oldField)
					{
						this->felder[oldField].standard();
						cout << "Player " << p + 1 << " is walked " << num << " field/s with his figure number " << figure + 1 << "\n\n";
					}
				}
			}
		}

}

int Spielfeld::checkFeld(Feld feld)
{
	if (feld.getStatus() == 1)
	{
		return 1;
	}
	else return 0;
}

void Spielfeld::dreheKarotte()
{
	int field, spieler, figurski, nOf, holeCount, fieldCount, n;
	holeCount = 0;
	fieldCount = 0;
	for (int i = 1; i <= 26; i++)
	{
		n = this->felder[i].getStatus();
		if (n == 0)
		{
			holeCount++;
		}
		if (n == 1)
		{
			fieldCount++;
		}
	}

	srand(time(NULL));

	nOf = rand() % 3 + 1;

	if (fieldCount >= holeCount*3)
	{
		for (int i = 1; i <= nOf; i++)
		{
			field = rand() % 25 + 1;
			cout << "\nField number " << field << " turns into a hole";
			if (this->felder[field].getStatus() == 2)
			{
				spieler = this->felder[field].getSpieler();
				figurski = this->felder[field].getFigur();
				this->players[spieler].figures[figurski].setFeld(0);
			}
			this->felder[field].werdeLoch();
		}
	}
	
	else if (fieldCount <= holeCount)
	{
		for (int i = 1; i <= nOf * 3; i++)
		{
			field = rand() % 25 + 1;
			if (this->felder[field].getStatus() == 0)
			{
				cout << "\nField number " << field << " turns from hole to normal field";
				this->felder[field].standard();
			}
		}
	}
	
	cout << "\n\n";
}

void Spielfeld::setWinner()
{
	this->winning = true;
}

bool Spielfeld::getWinner()
{
	return this->winning;
}

int Spielfeld::getWinningPlayer()
{
	return this->winner;
}