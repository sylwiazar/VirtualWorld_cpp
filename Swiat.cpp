#define _CRT_SECURE_NO_WARNINGS
#include "Swiat.h"
#include <algorithm>
#include <cstdlib>
#include <typeinfo>
#include <iostream>

int Swiat::GetSzerokosc() const
{
	return this->szerokosc_planszy;
}

int Swiat::GetIlosc_Organizmow() const
{
	return this->ile_organizmow;

}

void Swiat::NastepnaTura()
{
	SortujOrganizmy();

	int ilosc_organizmow_przed_rozpoczeciem_tury = ile_organizmow;

	for (int i = 0; i < ilosc_organizmow_przed_rozpoczeciem_tury; i++)
	{
		if (kolejka_ruchow[i].x != -2 && kolejka_ruchow[i].x != -1) //organizm, ktory by³ pod tym adresem zosta³ usuniêty z planszy
		{
			organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]->SetWiek(organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]->GetWiek()+1);

			informacje->WyzerujOrganizmy();

			if (organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]->SprawdzCzyZmieniPolozenie())
			{
				if (!organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]->Akcja(informacje))
				{
					Wspolrzedne pozycja_organizmu_do_walki = informacje->nowa_pozycja;

					organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]->Kolizja(organizmy[pozycja_organizmu_do_walki.x][pozycja_organizmu_do_walki.y], informacje);
				}
				else
				{
					Wspolrzedne pozycja = informacje->OrganizmAtakujacyDoPrzeniesienia;
				}
			}

			if (informacje->OrganizmUciekajacyDoUsuniecia.x >= 0)
			{
				Wspolrzedne pozycja_organizmu_do_usuniecia = informacje->nowa_pozycja;
				UsunOrganizm(organizmy[pozycja_organizmu_do_usuniecia.x][pozycja_organizmu_do_usuniecia.y], pozycja_organizmu_do_usuniecia, i);
			}
			if (informacje->OrganizmAtakujacyDoUsuniecia.x >= 0)
			{
				UsunOrganizm(organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y], kolejka_ruchow[i], i);
			}
			if (informacje->NowyOrganizm.x >= 0)
			{
				Organizm *dziecko = NoweDziecko(organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y]);
				DodajOrganizm(dziecko, informacje->NowyOrganizm, i);
			}
			if (informacje->OrganizmUciekajacyDoPrzeniesienia.x >= 0)
			{
				Wspolrzedne pozycjanowa = informacje->OrganizmUciekajacyDoPrzeniesienia;
				PrzeniesOrganizm(organizmy[informacje->nowa_pozycja.x][informacje->nowa_pozycja.y], informacje->nowa_pozycja, informacje->OrganizmUciekajacyDoPrzeniesienia, i);
			}
			if (informacje->OrganizmAtakujacyDoPrzeniesienia.x >= 0)
			{
				PrzeniesOrganizm(organizmy[kolejka_ruchow[i].x][kolejka_ruchow[i].y], kolejka_ruchow[i], informacje->OrganizmAtakujacyDoPrzeniesienia, i);
			}
			int ilosc = 4;
			while (ilosc--)
			{
				Wspolrzedne dousuniecia = informacje->ZwierzeciaDoUsuniecia[ilosc];
				if (dousuniecia.x>=0)
				{
					if (dynamic_cast<Zwierze *> (organizmy[dousuniecia.x][dousuniecia.y]))
					{
						informacje->komentator->ZjedliTrujaceRosliny(organizmy[dousuniecia.x][dousuniecia.y]->GetNazwa());
						UsunOrganizm(organizmy[dousuniecia.x][dousuniecia.y], dousuniecia, i);
						
					}
				}
			}
		}		
	}
}

int Swiat::GetWysokosc() const
{
	return this->wysokosc_planszy;
}

Wspolrzedne Swiat::LosujWolnaPozycje()
{
	while (1)
	{	
		Wspolrzedne pozycja;
		pozycja.x = rand() % this->szerokosc_planszy;
		pozycja.y = rand() % this->wysokosc_planszy;
		if (czy_zajete[pozycja.x][pozycja.y] == false)
		{
			czy_zajete[pozycja.x][pozycja.y] = true;
			return pozycja;
		}		
	}
}

Swiat::~Swiat()
{
}

void Swiat::PrzeprowadzGre(char decyzja)
{
	if (decyzja == 'n')
	{
		if (informacje->AktywowanaSpecjalnaUmiejetnosc)
		{
			informacje->CzasTrwaniaSpecjalnejUmiejetnosci++;
			if (informacje->CzasTrwaniaSpecjalnejUmiejetnosci == 5)
			{
				informacje->AktywowanaSpecjalnaUmiejetnosc = false;
				informacje->CzasTrwaniaSpecjalnejUmiejetnosci = 0;
				informacje->CzasDoUruchomieniaSpecjlanejUmiejetnosci = 5;
			}
		}
		else
		{
			if(informacje->CzasDoUruchomieniaSpecjlanejUmiejetnosci>0)
			informacje->CzasDoUruchomieniaSpecjlanejUmiejetnosci--;
		}
		NastepnaTura();
		system("cls");
		RysujSwiat();
		informacje->komentator->WypiszKomentarze();
	}
	else if (decyzja == 's')
	{
		if (informacje->CzasDoUruchomieniaSpecjlanejUmiejetnosci == 0)
		{
			informacje->AktywowanaSpecjalnaUmiejetnosc = true;
			printf("Wlaczono umiejetnosc specjalna dla czlowieka na 5 tur. \n");
		}
	}
	else if (decyzja == 'z')
	{
		this->ZapiszStanGry();
	}
}

void Swiat::ZapiszStanGry()
{
	FILE *plik;
	plik = fopen("StanGry.txt", "w");
	if (plik== NULL)
		printf("Nie udalo sie zapisac do pliku. \n");
	else
	{
		fprintf(plik, "%d %d %d", this->szerokosc_planszy, this->wysokosc_planszy, this->ile_organizmow);
		for (int i = 0; i < this->szerokosc_planszy; i++)
		{
			for (int j = 0; j < this->wysokosc_planszy; j++)
			{
				if (organizmy[i][j] != nullptr)
					fprintf(plik, "\n%d %d %d %d %c", i, j, organizmy[i][j]->GetSila(), organizmy[i][j]->GetWiek(), organizmy[i][j]->GetNazwa()[0]);
			}
		}
		fclose(plik);
		printf("Zapis do pliku zakonczony.\n");
	}
}

Swiat::Swiat( int szerokosc_planszy,  int wysokosc_planszy)
{
	this->szerokosc_planszy = szerokosc_planszy;
	this->wysokosc_planszy = wysokosc_planszy;
	this->organizmy = new Organizm**[szerokosc_planszy];
	this->czy_zajete = new bool*[szerokosc_planszy];
	this->kolejka_ruchow = new Wspolrzedne[wysokosc_planszy*szerokosc_planszy];
	for (int i = 0; i < szerokosc_planszy; i++)
	{
		organizmy[i] = new Organizm*[wysokosc_planszy];
		czy_zajete[i] = new bool[wysokosc_planszy];
	}
	this->ile_organizmow = 0;
	this->informacje = new Dane_o_Swiecie(wysokosc_planszy, szerokosc_planszy, czy_zajete);
	this->StworzSwiat();
	this->RysujSwiat();
}

Swiat::Swiat()
{
	int szerokosc_planszy;
	int wysokosc_planszy;
	int ile_organizmow;

	FILE *plik;
	plik=fopen("StanGry.txt","r");
	if (plik==NULL)
		printf("Nie udalo sie otworzyc pliku. \n");
	else
	{
		fscanf(plik, "%d %d %d\n", &szerokosc_planszy, &wysokosc_planszy, &ile_organizmow);
		this->szerokosc_planszy = szerokosc_planszy;
		this->wysokosc_planszy = wysokosc_planszy;
		this->organizmy = new Organizm**[szerokosc_planszy];
		this->czy_zajete = new bool*[szerokosc_planszy];
		this->kolejka_ruchow = new Wspolrzedne[wysokosc_planszy*szerokosc_planszy];
		for (int i = 0; i < szerokosc_planszy; i++)
		{
			organizmy[i] = new Organizm*[wysokosc_planszy];
			czy_zajete[i] = new bool[wysokosc_planszy];
		}
		this->ile_organizmow = ile_organizmow;
		this->informacje = new Dane_o_Swiecie(wysokosc_planszy, szerokosc_planszy, czy_zajete);
		for (int i = 0; i < szerokosc_planszy; i++)
		{
			for (int j = 0; j < wysokosc_planszy; j++)
			{
				organizmy[i][j] = nullptr;
				czy_zajete[i][j] = false;
			}
		}
		for (int i = 0; i < szerokosc_planszy * wysokosc_planszy; i++)
		{
			kolejka_ruchow[i] = { -1,-1 };
		}
		for (int i = 0; i < ile_organizmow; i++)
		{
			int  x, y, sila, wiek;
			char nazwa;
			fscanf(plik, "%d %d %d %d %c\n", &x, &y, &sila, &wiek, &nazwa);
			this->organizmy[x][y] = PrzywrocDoZycia(nazwa, x, y, sila, wiek);
			czy_zajete[x][y] = true;
			kolejka_ruchow[i] = {x,y};
		}
		fclose(plik);
		RysujSwiat();
	}

}

bool Swiat::SprawdzPozycje(Wspolrzedne pozycja)
{
	if (pozycja.x < 0 || pozycja.x >= szerokosc_planszy || pozycja.y < 0 || pozycja.y >= wysokosc_planszy)
		return false;
	return !(this->czy_zajete[pozycja.x][pozycja.y]);
}

Organizm* Swiat::NoweDziecko(Organizm * rodzic)
{
	Organizm *organizm;
	if (dynamic_cast<Antylopa *> (rodzic))
		organizm = new Antylopa;
	else if (dynamic_cast<BarszczSosnowskiego *> (rodzic))
		organizm = new BarszczSosnowskiego;
	else if (dynamic_cast<Guarana *> (rodzic))
		organizm = new Guarana;
	else if (dynamic_cast<Lis *> (rodzic))
		organizm = new Lis;
	else if (dynamic_cast<Mlecz *> (rodzic))
		organizm = new Mlecz;
	else if (dynamic_cast<Owca *> (rodzic))
		organizm = new Owca;
	else if (dynamic_cast<Trawa *> (rodzic))
		organizm = new Trawa;
	else if (dynamic_cast<WilczeJagody *> (rodzic))
		organizm = new WilczeJagody;
	else if (dynamic_cast<Wilk *> (rodzic))
		organizm = new Wilk;
	else
		organizm = new Zolw;
	
	return organizm;
}

Organizm* Swiat::PrzywrocDoZycia(char nazwa, int x, int y, int sila, int wiek)
{
	Organizm *organizm;
	
	if (nazwa== ANTYLOPA_NAZWA[0] )
		organizm = new Antylopa(x,y,sila,wiek);
	else if (nazwa == BARSZCZ_SOSNOWSKIEGO_NAZWA[0])
		organizm = new BarszczSosnowskiego(x, y, sila, wiek);
	else if (nazwa == GUARANA_NAZWA[0] )
		organizm = new Guarana(x, y, sila, wiek);
	else if (nazwa == LIS_NAZWA[0] )
		organizm = new Lis(x, y, sila, wiek);
	else if (nazwa == MLECZ_NAZWA[0] )
		organizm = new Mlecz(x, y, sila, wiek);
	else if (nazwa== OWCA_NAZWA[0] )
		organizm = new Owca(x, y, sila, wiek);
	else if (nazwa ==TRAWA_NAZWA[0] )
		organizm = new Trawa(x, y, sila, wiek);
	else if (nazwa == WILCZE_JAGODY_NAZWA[0] )
		organizm = new WilczeJagody(x, y, sila, wiek);
	else if (nazwa == WILK_NAZWA[0] )
		organizm = new Wilk(x, y, sila, wiek);
	else
		organizm = new Zolw(x, y, sila, wiek);

	return organizm;

}

void Swiat::StworzSwiat()
{
	for (int i = 0; i < szerokosc_planszy; i++)
	{
		for (int j = 0; j < wysokosc_planszy; j++)
		{
				organizmy[i][j] = nullptr;
				czy_zajete[i][j] = false;
		}
	}
	for (int i = 0; i < szerokosc_planszy * wysokosc_planszy; i++)
	{
		kolejka_ruchow[i] = { -1,-1 };
	}
	Lis *lis = new Lis;
	Antylopa *antylopa = new Antylopa;
	Owca *owca = new Owca;
	Wilk *wilk = new Wilk;
	Zolw *zolw = new Zolw;

	Czlowiek *czlowiek = new Czlowiek;

	BarszczSosnowskiego *barszcz = new BarszczSosnowskiego;
	Guarana *guarana = new Guarana;
	Mlecz *mlecz = new Mlecz;
	Trawa *trawa = new Trawa;
	WilczeJagody *jagody = new WilczeJagody;


	DodajOrganizm(lis, this->LosujWolnaPozycje(), -1);
	DodajOrganizm(antylopa, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(owca, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(wilk, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(zolw, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(czlowiek, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(barszcz, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(guarana, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(mlecz, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(trawa, this->LosujWolnaPozycje(),-1);
	DodajOrganizm(jagody, this->LosujWolnaPozycje(),-1);

	int ile = szerokosc_planszy * wysokosc_planszy / 3 - 10;
	
	while (ile--)
	{
		int losuj = rand() % 10;
		if (losuj == 0)
		{
			Lis *lis = new Lis;
			DodajOrganizm(lis, this->LosujWolnaPozycje(), -1);
		}
		else if (losuj == 1)
		{
			Antylopa *antylopa = new Antylopa;
			DodajOrganizm(antylopa, this->LosujWolnaPozycje(),-1);
		}			
		else if (losuj == 2)
		{
			Owca *owca = new Owca;
			DodajOrganizm(owca, this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 3)
		{
			Wilk *wilk = new Wilk;
			DodajOrganizm(wilk, this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 4)
		{
			Zolw *zolw = new Zolw;
			DodajOrganizm(zolw , this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 5)
		{
			BarszczSosnowskiego *barszcz = new BarszczSosnowskiego;
			DodajOrganizm(barszcz, this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 6)
		{
			Guarana *guarana = new Guarana;
			DodajOrganizm(guarana, this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 7)
		{
			Mlecz *mlecz = new Mlecz;
			DodajOrganizm(mlecz, this->LosujWolnaPozycje(),-1);
		}
		else if (losuj == 8)
		{
			Trawa *trawa = new Trawa;
			DodajOrganizm(trawa, this->LosujWolnaPozycje(),-1);
		}
		else
		{
			WilczeJagody *jagody = new WilczeJagody;
			DodajOrganizm(jagody, this->LosujWolnaPozycje(),-1);
		}
	}
}


void Swiat::SortujOrganizmy()
{
	for (int i = szerokosc_planszy * wysokosc_planszy - 1; i>0 ; i--)
	{
		for (int j = szerokosc_planszy * wysokosc_planszy - 1; j > 0 ; j--)
		{
			if (kolejka_ruchow[j].x == -2)
			{
				kolejka_ruchow[j].x = -1;
				kolejka_ruchow[j].y = -1;
			}

			if ((kolejka_ruchow[j-1].x >=0)&&(kolejka_ruchow[j].x >= 0))
			{
				if ((organizmy[kolejka_ruchow[j].x][kolejka_ruchow[j].y]->GetInicjatywa()) > (organizmy[kolejka_ruchow[j - 1].x][kolejka_ruchow[j - 1].y]->GetInicjatywa()))
				{
				std:: swap(kolejka_ruchow[j], kolejka_ruchow[j - 1]);
				}
				else if((organizmy[kolejka_ruchow[j].x][kolejka_ruchow[j].y]->GetInicjatywa()) == (organizmy[kolejka_ruchow[j - 1].x][kolejka_ruchow[j - 1].y]->GetInicjatywa()))
				{
					if ((organizmy[kolejka_ruchow[j].x][kolejka_ruchow[j].y]->GetWiek()) > (organizmy[kolejka_ruchow[j - 1].x][kolejka_ruchow[j - 1].y]->GetWiek()))
					{
						std::swap(kolejka_ruchow[j], kolejka_ruchow[j - 1]);
					}
				}
			}
			else if(kolejka_ruchow[j - 1].x < 0)
				std::swap(kolejka_ruchow[j], kolejka_ruchow[j - 1]);
		}
	}
}

void Swiat::DodajOrganizm(Organizm *org, const Wspolrzedne pozycja, int j)
{
	czy_zajete[pozycja.x][pozycja.y] = true;
	this->organizmy[pozycja.x][pozycja.y] = org;
	
	for (int i = 0; i < wysokosc_planszy * szerokosc_planszy; i++)
	{
		if (j >= 0)
		{
			if (i < j &&  kolejka_ruchow[i].x == -2)
			{
				kolejka_ruchow[i] = pozycja;
				break;
			}
		}
		if (kolejka_ruchow[i].x == -1)
		{
			kolejka_ruchow[i] = pozycja;
			break;
		}
	}
	
	this->ile_organizmow++;
	this->organizmy[pozycja.x][pozycja.y]->SetPozycja(pozycja);
}

void Swiat::PrzeniesOrganizm(Organizm * org, Wspolrzedne stara_pozycja, Wspolrzedne nowa_pozycja, int i)
{
	organizmy[stara_pozycja.x][stara_pozycja.y] = nullptr;
	czy_zajete[stara_pozycja.x][stara_pozycja.y] = false;
	czy_zajete[nowa_pozycja.x][nowa_pozycja.y] = true;
	organizmy[nowa_pozycja.x][nowa_pozycja.y] = org;

	for (int j = 0; j < szerokosc_planszy * wysokosc_planszy; j++)
	{
		if ((kolejka_ruchow[j].x == stara_pozycja.x) && (kolejka_ruchow[j].y == stara_pozycja.y))
		{
			kolejka_ruchow[j] = nowa_pozycja;
			org->SetPozycja(nowa_pozycja);
			break;
		}
	}
}

void Swiat::UsunOrganizm(Organizm * org, Wspolrzedne pozycja, int i)
{
	delete org;
	organizmy[pozycja.x][pozycja.y] = nullptr;
	czy_zajete[pozycja.x][pozycja.y] = false;
	ile_organizmow--;
	for (int j = 0; j < szerokosc_planszy * wysokosc_planszy; j++)
	{
		if ((kolejka_ruchow[j].x == pozycja.x) && (kolejka_ruchow[j].y == pozycja.y))
		{
			kolejka_ruchow[j] = { -2,-2 };
			break;
		}		
	}
}

void Swiat::RysujSwiat()
{
	printf("Antylopa %c Lis %c Owca %c Wilk %c Zolw %c Czlowiek %c\n", ANTYLOPA, LIS, OWCA, WILK, ZOLW, CZLOWIEK);
	printf("Barszcz S. %c Guarana %c Mlecz %c Trawa %c Wilcze J. %c\n", BARSZCZ_SOSNOWSKIEGO, GUARANA, MLECZ, TRAWA, WILCZE_JAGODY);
	printf("Nastepna tura n Wyjscie q Specjalna Umiejetnosc s Zapis Stanu Gry z\n\n");


	for (int i = 0; i < this->wysokosc_planszy + 2 ; i++)
	{
		printf("|");
		for (int j = 0; j < this->szerokosc_planszy ; j++)
		{
			if ((i == 0) || (i == this->wysokosc_planszy + 1))
			{
				printf("-");
			}
			else
			{
				if (organizmy[j][i-1] != nullptr)
					this->organizmy[j][i-1]->Rysuj();
				else
					printf(" ");
			}
		}
		printf("|");
		printf("\n");
	}
}

void Swiat::RozpocznijGre()
{
	this->StworzSwiat();
	this->RysujSwiat();
}