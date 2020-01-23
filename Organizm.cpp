#include "Organizm.h"
#include <iostream>


Organizm::Organizm(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol)
	:nazwa(nazwa), sila(sila), inicjatywa(inicjatywa), symbol(symbol)
{
	wiek = 0;
}

Organizm::Organizm(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol, int wiek, int x, int y)
	: nazwa(nazwa), sila(sila), inicjatywa(inicjatywa), symbol(symbol), wiek(wiek), pozycja({ x,y })
{
}

void Organizm::Rysuj() const
{
	printf("%c", this->GetSymbol());
}

Wspolrzedne Organizm::ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(Wspolrzedne pozycja, Dane_o_Swiecie *informacje, int zasieg_ruchu)
{
	bool czyjestwolnemiejsce = false;
	if (pozycja.x - zasieg_ruchu >= 0 && informacje->SprawdzCzyPoleJestWolne(pozycja.x - zasieg_ruchu, pozycja.y))
	{
		czyjestwolnemiejsce = true;
	}
	if (pozycja.x + zasieg_ruchu <= informacje->GetSzerokosc()- 1 && informacje->SprawdzCzyPoleJestWolne(pozycja.x + zasieg_ruchu, pozycja.y))
	{
		czyjestwolnemiejsce = true;
	}
	if (pozycja.y - zasieg_ruchu >= 0 && informacje->SprawdzCzyPoleJestWolne(pozycja.x, pozycja.y - zasieg_ruchu))
	{
		czyjestwolnemiejsce = true;
	}
	if (pozycja.y + zasieg_ruchu < informacje->GetWysokosc() && informacje->SprawdzCzyPoleJestWolne(pozycja.x, pozycja.y + zasieg_ruchu))
	{
		czyjestwolnemiejsce = true;
	}
	if (czyjestwolnemiejsce)
	{
		while (1)
		{
			Wspolrzedne nowa_pozycja = WylosujPozycje(pozycja, informacje, zasieg_ruchu);
			if (informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x, nowa_pozycja.y))
			{
				return nowa_pozycja;
			}
		}
	}
	else
		return pozycja;
}

Wspolrzedne Organizm::WylosujPozycje(Wspolrzedne pozycja, Dane_o_Swiecie * informacje, int zasieg_ruchu)
{
	while (1)
	{
		int kierunek = rand() % 4;
		if (kierunek == 0 && pozycja.x - zasieg_ruchu >= 0)
		{
			pozycja.x -= zasieg_ruchu;
			return pozycja;
		}
		else if (kierunek == 1 && pozycja.x + zasieg_ruchu < informacje->GetSzerokosc())
		{
			pozycja.x += zasieg_ruchu;
			return pozycja;
		}
		else if (kierunek == 2 && pozycja.y - zasieg_ruchu >= 0)
		{
			pozycja.y -= zasieg_ruchu;
			return pozycja;
		}
		else if(pozycja.y + zasieg_ruchu < informacje->GetWysokosc())
		{
			pozycja.y += zasieg_ruchu;
			return pozycja;			
		}
	}
}

bool Organizm::SprawdzCzyZmieniPolozenie()
{
	return true;
}

void Organizm::ZwiekszSileZwierzecia(Organizm *org)
{
}

bool Organizm::SprawdzCzyOdwazySieWalczycZSilniejszymOrganizmem(int sila_przeciwnika)
{
	return true;
}

bool Organizm::ZjedzenieSmiertelnejRosliny()
{
	return false;
}

bool Organizm::CzyWMomencieAtakuUcieknieNaInneMiejsce()
{
	return false;
}

bool Organizm::SprawdzCzyOdbijeAtak(int sila_przeciwnika)
{
	return false;
}

void Organizm::ZabijWszystkieSasiednieOrganizmy(Wspolrzedne pozycja, Dane_o_Swiecie *informacje)
{
}

void Organizm::SetPozycja(Wspolrzedne pozycja)
{
	this->pozycja = pozycja;
}

void Organizm::SetSila(int nowaSila)
{
	this->sila = nowaSila;
}

void Organizm::SetWiek(int wiek)
{
	this->wiek = wiek;
}

char Organizm::GetSymbol() const
{
	return this->symbol;
}

std::string Organizm::GetNazwa() const
{
	return this->nazwa;
}

int Organizm::GetSila() const
{
	return this->sila;
}

int Organizm::GetInicjatywa() const
{
	return this->inicjatywa;
}

int Organizm::GetWiek() const
{
	return this->wiek;
}

Wspolrzedne Organizm::GetPozycja() const
{
	return this->pozycja;
}

Organizm::~Organizm()
{
}