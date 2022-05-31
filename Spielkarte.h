#pragma once
#include <string>

using namespace std;

class Spielkarte
{
public:
	Spielkarte(int bild);
	Spielkarte();
	~Spielkarte();

	void setBild(int n);
	int getBild();

private:
	int bild;
};