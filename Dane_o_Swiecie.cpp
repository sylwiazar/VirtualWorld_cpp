#include "Dane_o_Swiecie.h"



Dane_o_Swiecie::Dane_o_Swiecie(int wysokosc, int szerokosc, bool **wolne_pole)
{
	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
	this->zajete_pole = wolne_pole;
	this->CzasDoUruchomieniaSpecjlanejUmiejetnosci = 0;
	this->CzasTrwaniaSpecjalnejUmiejetnosci = 0;
	this->AktywowanaSpecjalnaUmiejetnosc = false;
	this->komentator = new Komentator();
}

int Dane_o_Swiecie::GetSzerokosc() const
{
	return szerokosc;
}

int Dane_o_Swiecie::GetWysokosc() const
{
	return wysokosc;
}


void Dane_o_Swiecie::WyzerujOrganizmy()
{
	this->OrganizmUciekajacyDoUsuniecia = { -1,-1 };
	this->OrganizmAtakujacyDoUsuniecia = { -1,-1 };
	this->NowyOrganizm = { -1,-1 };
	this->OrganizmUciekajacyDoPrzeniesienia = { -1,-1 };
	this->OrganizmAtakujacyDoPrzeniesienia = { -1,-1 };
	this->ZwierzeciaDoUsuniecia[0]= { -1,-1 };
	this->ZwierzeciaDoUsuniecia[1] = { -1,-1 };
	this->ZwierzeciaDoUsuniecia[2] = { -1,-1 };
	this->ZwierzeciaDoUsuniecia[3] = { -1,-1 };
}


bool Dane_o_Swiecie::SprawdzCzyPoleJestWolne(int x, int y) const //zwroci true jesli wolne
{
	return !zajete_pole[x][y];
}


Dane_o_Swiecie::~Dane_o_Swiecie()
{
}