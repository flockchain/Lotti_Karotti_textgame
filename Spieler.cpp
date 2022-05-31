#pragma once
#include <vector>
#include "Spieler.h"
#include "Spielfigur.h"

using namespace std;

Spieler::Spieler()
{
	this->name = name;
	this->farbe = farbe;
}

Spieler::~Spieler()
{
	
}



void Spieler::initFigures()
{
	for (int i = 0; i <= 3; i++)
	{
		this->figures.push_back(Spielfigur());
	}
	this->figures.resize(4);
	for (int i = 0; i <= 3; i++)
	{
		this->figures[i].setNummer(i);
	}
}

void Spieler::setName(string name)
{
	this->name = name;
}

void Spieler::setFarbe(string farbe)
{
	this->farbe = farbe;
}

string Spieler::getName()
{
	return this->name;
}

string Spieler::getFarbe()
{
	return this->farbe;
}