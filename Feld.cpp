#pragma once
#include "Feld.h"

using namespace std;

Feld::Feld()
{
	this->status = 0;
	this->spieler = 0;
	this->figur = 0;
}

Feld::~Feld()
{

}

void Feld::werdeLoch()
{
	this->status = 0;
	this->figur = 0;
	this->spieler = 0;
}

void Feld::belegung(int figur, int spieler)
{
	this->status = 2;
	this->spieler = spieler;
	this->figur = figur;
}

void Feld::standard()
{
	this->status = 1;
	this->spieler = 0;
	this->figur = 0;
}

int Feld::getStatus()
{
	return this->status;
}

int Feld::getFigur()
{
	return this->figur;
}

int Feld::getSpieler()
{
	return this->spieler;
}