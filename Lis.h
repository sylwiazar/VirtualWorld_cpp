#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
	Lis();
	Lis(int x, int y, int sila, int wiek);
	~Lis();

protected:
	//Lis czuwa i nie przesunie siê na pole, gdzie znajduje sie silniejszy organizm
	//Gdy, na polu jest taki organizm, Lis po prostu zostaje na swoim miejscu
	virtual bool SprawdzCzyOdwazySieWalczycZSilniejszymOrganizmem(int sila_przeciwnika) override;
};

