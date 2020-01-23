#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego()
	:Roslina(BARSZCZ_SOSNOWSKIEGO_NAZWA, BARSZCZ_SOSNOWSKIEGO_SILA, BARSZCZ_SOSNOWSKIEGO_INICJATYWA, BARSZCZ_SOSNOWSKIEGO)
{
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, int sila, int wiek)
	: Roslina(BARSZCZ_SOSNOWSKIEGO_NAZWA,sila, BARSZCZ_SOSNOWSKIEGO_INICJATYWA, BARSZCZ_SOSNOWSKIEGO, wiek, x, y)
{
}

bool BarszczSosnowskiego::ZjedzenieSmiertelnejRosliny()
{
	return true;
}

void BarszczSosnowskiego::ZabijWszystkieSasiednieOrganizmy(Wspolrzedne pozycja, Dane_o_Swiecie *informacje)
{
	if (pozycja.x + 1 < informacje->GetSzerokosc())
	{
		Wspolrzedne nowa_pozycja = pozycja;
		if (!informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x+1, nowa_pozycja.y))
		{
			nowa_pozycja.x += 1;
			informacje->ZwierzeciaDoUsuniecia[0] = nowa_pozycja;
		}
	}
	if (pozycja.x - 1 >= 0)
	{
		Wspolrzedne nowa_pozycja = pozycja;
		if (!informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x - 1, nowa_pozycja.y))
		{
			nowa_pozycja.x -= 1;
			informacje->ZwierzeciaDoUsuniecia[1] = nowa_pozycja;
		}
	}
	if (pozycja.y + 1 < informacje->GetWysokosc() )
	{
		Wspolrzedne nowa_pozycja = pozycja;
		if (!informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x, nowa_pozycja.y+1))
		{
			nowa_pozycja.y += 1;
			informacje->ZwierzeciaDoUsuniecia[2] = nowa_pozycja;
		}
	}
	if (pozycja.y - 1 >= 0)
	{
		Wspolrzedne nowa_pozycja = pozycja;
		nowa_pozycja.y -= 1;
		if (!informacje->SprawdzCzyPoleJestWolne(nowa_pozycja.x, nowa_pozycja.y))
		{
			informacje->ZwierzeciaDoUsuniecia[3] = nowa_pozycja;
		}
	}
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}