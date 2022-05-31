#pragma once
#include "Spielkarte.h"

Spielkarte::Spielkarte(int bild)
{
	this->bild = bild;
}

Spielkarte::Spielkarte()
{
	this->bild = 0;
}

Spielkarte::~Spielkarte()
{

}

int Spielkarte::getBild()
{
	return this->bild;
}

void Spielkarte::setBild(int n)
{
	this->bild = n;
}