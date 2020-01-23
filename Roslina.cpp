#include "Roslina.h"
#include <time.h>
Roslina::Roslina(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol)
	:Organizm(nazwa, sila, inicjatywa, symbol)
{
}

Roslina::Roslina(const std::string & nazwa, const int & sila, const int & inicjatywa, const char & symbol, int wiek, int x, int y)
	: Organizm(nazwa, sila, inicjatywa, symbol, wiek, x, y)
{
}


void Roslina::Kolizja(Organizm * org, Dane_o_Swiecie *informacje)
{}

bool Roslina::ZasiejRosline()
{
	if (rand() % 100 < ROZPRZESTRZENIANIE_ROSLIN)
	{
		return true;
	}
	return false;
}

bool Roslina::Akcja(Dane_o_Swiecie *informacje)
{
	//dzia³a wy³¹cznie dla barszczu
	

	//Zwraca true, jesli roslina sie rozprzestrzenia
	if (ZasiejRosline()) 
	{
		Wspolrzedne pozycja_rodzica = this->GetPozycja();
		Wspolrzedne pozycja_dla_dziecka = ZnajdzPozycjeXOddalonaOdDanegoOrganizmu(pozycja_rodzica, informacje, ZASIEG_RUCHU_DEFAULT);

		//Jesli pozycja dziecka i rodzica s¹ takie same, to znaczy, ¿e wokó³ rodzica nie ma wolnego miejsca, w którym mog³oby zasiaæ roœlinê
		if (pozycja_dla_dziecka.x != pozycja_rodzica.x || pozycja_dla_dziecka.y != pozycja_rodzica.y)
		{
			informacje->NowyOrganizm = pozycja_dla_dziecka;
			informacje->komentator->NoweOrganizmy(this->GetNazwa());
		}
	}
	this->ZabijWszystkieSasiednieOrganizmy(this->GetPozycja(), informacje);
	return true;
}

Roslina::~Roslina()
{
}