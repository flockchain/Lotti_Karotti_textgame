#pragma once
#include <iostream>
#include "Spielfigur.h"

using namespace std;

Spielfigur::Spielfigur()
{
	this->nummer = 0;
	this->feld = 0;
}

Spielfigur::~Spielfigur()
{

}

int Spielfigur::getFeld()
{
	return this->feld;
}

int Spielfigur::getNummer()
{
	return this->nummer;
}

void Spielfigur::geheFelder(int felder)
{
	this->feld += felder;
}

void Spielfigur::setNummer(int num)
{
	this->nummer = num;
}

void Spielfigur::setFeld(int neu)
{
	this->feld = neu;
}