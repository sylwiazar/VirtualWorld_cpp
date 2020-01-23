#include "Trawa.h"

Trawa::Trawa()
	:Roslina(TRAWA_NAZWA, TRAWA_SILA, TRAWA_INICJATYWA, TRAWA)
{
}

Trawa::Trawa(int x, int y, int sila, int wiek)
	: Roslina(TRAWA_NAZWA, sila, TRAWA_INICJATYWA, TRAWA, wiek, x, y)
{
}

Trawa::~Trawa()
{
}