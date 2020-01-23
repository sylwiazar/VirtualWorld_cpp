#include "Komentator.h"
#include <iostream>
using namespace std;

Komentator::Komentator()
{
	this-> zjedzone_rosliny= "Zjedzone rosliny w danej turze: ";
	this->w_wyniku_walk_zgineli= "W wyniku walk zgineli: ";
	this->nowe_organizmy = "Nowe organizmy na planszy: ";
	this->zjedli_trujace_rosliny = "Trujace rosliny zabily: ";
}

void Komentator::WWynikuWalkZgineli(const std::string nazwa)
{
	this->w_wyniku_walk_zgineli.append(nazwa);
	this->w_wyniku_walk_zgineli.append(" ");
}

void Komentator::ZjedzoneRosliny(const std::string nazwa)
{
	this->zjedzone_rosliny.append(nazwa);
	this->zjedzone_rosliny.append(" ");
}

void Komentator::NoweOrganizmy(const std::string nazwa)
{
	this->nowe_organizmy.append(nazwa);
	this->nowe_organizmy.append(" ");
}

void Komentator::ZjedliTrujaceRosliny(const std::string nazwa)
{
	this->zjedli_trujace_rosliny.append(nazwa);
	this->zjedli_trujace_rosliny.append(" ");
}

void Komentator::WypiszKomentarze()
{
	if(zjedzone_rosliny!= "Zjedzone rosliny w danej turze: ")
	cout << zjedzone_rosliny << endl;
	if (w_wyniku_walk_zgineli != "W wyniku walk zgineli: ")
	cout << w_wyniku_walk_zgineli << endl;
	if (nowe_organizmy != "Nowe organizmy na planszy: ")
	cout << nowe_organizmy << endl;
	if (zjedli_trujace_rosliny != "Trujace rosliny zabily: ")
	cout << zjedli_trujace_rosliny << endl;

	this->zjedzone_rosliny = "Zjedzone rosliny w danej turze: ";
	this->w_wyniku_walk_zgineli = "W wyniku walk zgineli: ";
	this->nowe_organizmy = "Nowe organizmy na planszy: ";
	this->zjedli_trujace_rosliny = "Trujace rosliny zabily: ";
}

Komentator::~Komentator()
{
}