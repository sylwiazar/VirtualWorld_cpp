#include "Antylopa.h"

Antylopa::Antylopa()
	:Zwierze(ANTYLOPA_NAZWA, ANTYLOPA_SILA, ANTYLOPA_INICJATYWA,ANTYLOPA, ZASIEG_RUCHU_ANTYLOPY)
{
}

Antylopa::Antylopa(int x, int y, int sila, int wiek)
	: Zwierze(ANTYLOPA_NAZWA,sila, ANTYLOPA_INICJATYWA, ANTYLOPA, ZASIEG_RUCHU_ANTYLOPY, wiek, x, y)
{
}

bool Antylopa::CzyWMomencieAtakuUcieknieNaInneMiejsce()
{
	int szansa_na_ucieczke = rand() % 100;
	if (szansa_na_ucieczke < 50)
	{
		return true;
	}
		return false;
}

Antylopa::~Antylopa()
{
}