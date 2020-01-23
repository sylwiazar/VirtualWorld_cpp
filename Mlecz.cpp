#include "Mlecz.h"

Mlecz::Mlecz()
	:Roslina(MLECZ_NAZWA, MLECZ_SILA, MLECZ_INICJATYWA, MLECZ)
{
}

Mlecz::Mlecz(int x, int y, int sila, int wiek)
	: Roslina(MLECZ_NAZWA, sila, MLECZ_INICJATYWA, MLECZ, wiek, x, y)
{
}

bool Mlecz::ZasiejRosline()
{
	int ilosc_prob = PROBY_ROZPRZESTRZENIENIA_MLECZA;
	while (ilosc_prob--)
	{	
		if (Roslina::ZasiejRosline())
		{
			return true;
		}
	}
	return false;
}

Mlecz::~Mlecz()
{
}