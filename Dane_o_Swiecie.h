#pragma once
#include "CONST.h"
#include "Organizm.h"
#include "Komentator.h"

class Dane_o_Swiecie
{
public:
	Dane_o_Swiecie(int wysokosc, int szerokosc, bool **wolne_pole);
	
	Komentator *komentator;

	Wspolrzedne OrganizmUciekajacyDoUsuniecia;
	Wspolrzedne OrganizmAtakujacyDoUsuniecia;
	Wspolrzedne NowyOrganizm;
	Wspolrzedne OrganizmUciekajacyDoPrzeniesienia;
	Wspolrzedne OrganizmAtakujacyDoPrzeniesienia;
	Wspolrzedne ZwierzeciaDoUsuniecia[4];
	Wspolrzedne nowa_pozycja;

	//Odlicza, przez ile tur jest aktywowana
	int CzasTrwaniaSpecjalnejUmiejetnosci;
	//odlicza czas, po jakim ponownie bedzie mozna uaktywnic umiejetnosc specjalna
	int CzasDoUruchomieniaSpecjlanejUmiejetnosci;
	//Sprawdza, czy specjalna umiejetnosc jest aktywowana
	bool AktywowanaSpecjalnaUmiejetnosc;
	
	int GetSzerokosc() const;
	int GetWysokosc() const;

	//Przed rozpoczeciem tury ustawia pozycje wszystkich organizmow na -1
	void WyzerujOrganizmy();

	//Zwraca true, jeœli pole jest wolne
	bool SprawdzCzyPoleJestWolne(int x, int y) const;

	~Dane_o_Swiecie();

private:
	int szerokosc;
	int wysokosc;
	bool **zajete_pole;
};

