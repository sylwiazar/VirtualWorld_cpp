#pragma once
#include "Organizm.h"
#include "Dane_o_Swiecie.h"
#include "CONST.h"

class Zwierze : public Organizm
{

public:

	Zwierze(const std::string &nazwa, const int &sila, const int &inicjatywa, const char &symbol, const int &zasieg_ruchu);
	Zwierze(const std::string &nazwa, const int &sila, const int &inicjatywa, const char &symbol, const int &zasieg_ruchu, int wiek, int x, int y);
	int GetZasiegRuchu() const;

	~Zwierze();

protected:
	bool Akcja(Dane_o_Swiecie *informacje) override;
	void Kolizja(Organizm *org, Dane_o_Swiecie *informacje) override;
	Wspolrzedne WykonajRuch(int zasieg_ruchu, Dane_o_Swiecie *informacje, Wspolrzedne pozycja);

	//Zwraca true, jesli dwa organizmy s¹ tej samej klasy
	bool SprawdzCzyToTeSameOrganizmy(Organizm *org);

private:
	int zasieg_ruchu;
};