#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana();
	Guarana(int x, int y, int sila, int wiek);
	~Guarana();

protected:
	//Organizm, kt�ry zjad� guaran�
	//zwieksza swoj� si�� o 3
	void ZwiekszSileZwierzecia(Organizm *org) override;
};

