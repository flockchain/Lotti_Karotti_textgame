#pragma once
#include <vector>
#include <iostream>
#include <stdio.h>
#include "LottiKarotti.h"
#include "Spielfeld.h"

using namespace std;

LottiKarotti::LottiKarotti()
{
	cout << "A game named Lotti Karotti was created" << endl;
	this->run = true;
}

LottiKarotti::~LottiKarotti()
{
	cout << "The game Lotti Karotti was destroyed" << endl;
}

void LottiKarotti::start()
{
	cout << "\n\nHello and welcome to Lotti Karotti\n\n";
	int s, winPlay;
	string theName, theColor;
	Spielfeld *board = new Spielfeld();

	cout << "\n\nIm folgenden sehen sie nicht besetzte Felder als -> O\nLoecher als -> ( )\n\n";
	s = board->players.size();
	board->players.resize(s);
	int z = 99;
	bool w;
	int h;
	//Spiele bis einer gewonnen hat
	do
	{
		//Zug beginnt
		for (int i = 0; i <= s-2; i++)
		{
			//Ausgabe aktuelle Situation
			board->feldAusgabe();

			cout << "\n\nIt's the turn of player " << i+1;
			h = board->karteZiehen(z);
			if (h != 4)
			{
				cout << "\nPlayer number " << i+1 << " can move one of his figures " << h << " fields";
				board->figurBewegen(h, i, s);
			}
			else if (h == 4)
			{
				cout << "\nPlayer number " << i+1 << " needs to turn the carrot ->";
				board->dreheKarotte();
			}
			z--;

			w = board->getWinner();
		
			if (w == true)
			{
				this->run = false;
			}
		}

	} while (this->run == true);
	winPlay = board->getWinningPlayer();
	cout << "\n\n\nPlayer number " << winPlay << " moved one of his figures to the last field and won the game!!!";
	cout << "\n\n CONGRULATIONS!!!!!!!!!";

	delete board;
}