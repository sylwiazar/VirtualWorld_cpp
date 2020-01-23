#pragma once

#include <vector>
#include "Organizm.h"
#include "Zwierzeta.h"
#include "Rosliny.h"
#include "Czlowiek.h"
#include "CONST.h"
#include <cstdio>
#include "Dane_o_Swiecie.h"
#include "Komentator.h"

class Swiat
{
public:

	Swiat(int szerokosc_planszy, int wysokosc_planszy);//sprawdz
	Swiat();

	void PrzeprowadzGre(char decyzja);

	int GetWysokosc() const;//sprawdz
	int GetSzerokosc() const;//sprawdz
	int GetIlosc_Organizmow() const;

	~Swiat();//sprawdz

protected:

	void ZapiszStanGry();
	void NastepnaTura();
	Organizm* PrzywrocDoZycia(char nazwa, int x, int y, int sila, int wiek);

	void RysujSwiat();
	void DodajOrganizm(Organizm *nowy, Wspolrzedne pozycja, int i );
	void PrzeniesOrganizm(Organizm *org, Wspolrzedne stara_pozycja, Wspolrzedne nowa_pozycja, int i);
	void UsunOrganizm(Organizm *org, Wspolrzedne pozycja, int i);
	Organizm* NoweDziecko(Organizm *rodzic);
	void StworzSwiat();
	bool SprawdzPozycje(Wspolrzedne pozycja);
	Wspolrzedne LosujWolnaPozycje();
	void RozpocznijGre();

private:
	void SortujOrganizmy();
	Wspolrzedne *kolejka_ruchow;
	int szerokosc_planszy;
	int wysokosc_planszy;
	int ile_organizmow;
	Dane_o_Swiecie *informacje;
	//sprawdza czy dane pole planszy jest zajete
	bool **czy_zajete;
	Organizm*** organizmy;
};

