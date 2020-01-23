#include "Guarana.h"

Guarana::Guarana()
	:Roslina(GUARANA_NAZWA, GUARANA_SILA, GUARANA_INICJATYWA, GUARANA)
{
}

Guarana::Guarana(int x, int y, int sila, int wiek)
	: Roslina(GUARANA_NAZWA, sila, GUARANA_INICJATYWA, GUARANA, wiek, x,y)
{
}

void Guarana::ZwiekszSileZwierzecia(Organizm * org)
{
	org->SetSila(org->GetSila() + ZWIEKSZENIE_SILY_PRZY_ZJEDZENIU_GUARANY);
}

Guarana::~Guarana()
{
}