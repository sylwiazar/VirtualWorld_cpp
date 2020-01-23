#include "WilczeJagody.h"

WilczeJagody::WilczeJagody()
	:Roslina(WILCZE_JAGODY_NAZWA, WILCZE_JAGODY_SILA, WILCZE_JAGODY_INICJATYWA, WILCZE_JAGODY)
{
}

WilczeJagody::WilczeJagody(int x, int y, int sila, int wiek)
	: Roslina(WILCZE_JAGODY_NAZWA, sila, WILCZE_JAGODY_INICJATYWA, WILCZE_JAGODY, wiek, x, y)
{
}

bool WilczeJagody::ZjedzenieSmiertelnejRosliny()
{
	return true;
}

WilczeJagody::~WilczeJagody()
{
}