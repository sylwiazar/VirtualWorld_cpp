#pragma once
#include "Zwierze.h"
#include "CONST.h"

class Antylopa : public Zwierze
{
public:
	Antylopa();
	Antylopa(int x, int y,int sila,int wiek);
	~Antylopa();

protected:

	//Antylopa ma 50% szans, �e ucieknie na inne miejsce,
	//je�li zaatakuje j� organizm silniejszy
	bool CzyWMomencieAtakuUcieknieNaInneMiejsce() override;
};

