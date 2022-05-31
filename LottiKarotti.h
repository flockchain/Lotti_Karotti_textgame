#pragma once
#include "Spielfeld.h"
#include "Spieler.h"
#include "Spielfigur.h"

class LottiKarotti
{
public:
	LottiKarotti();
	~LottiKarotti();

	void start();

private:

	bool run;
};