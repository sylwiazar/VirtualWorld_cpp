#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana();
	Guarana(int x, int y, int sila, int wiek);
	~Guarana();

protected:
	//Organizm, który zjad³ guaranê
	//zwieksza swoj¹ si³ê o 3
	void ZwiekszSileZwierzecia(Organizm *org) override;
};

