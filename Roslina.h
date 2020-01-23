#pragma once
#include "Organizm.h"
#include "CONST.h"

class Roslina : public Organizm
{
public:
	Roslina(const std::string &nazwa,  const int &sila, const int &inicjatywa, const char &symbol);
	Roslina(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol, int wiek, int x, int y);
	~Roslina();

protected:
	//Rosliny sie nie poruszaja
	bool Akcja(Dane_o_Swiecie *informacje) override;

	//Dla roslin do kolizji nigdy nie dochodzi
	void Kolizja(Organizm *org, Dane_o_Swiecie *informacje) override;

	//Sprawdza, czy roslina zasieje swoje nasiona
	//Zwraca true - jeœli w danej turze roœlina siê rozprzestrzenia
	virtual bool ZasiejRosline();
};