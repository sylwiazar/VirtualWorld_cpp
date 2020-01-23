#pragma once

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <string>
#include <windows.h>
#include <fstream>

//SYMBOLE

#define CZLOWIEK 'x'

//Zwierzeta
#define WILK 'W'
#define OWCA 'O'
#define LIS 'L'
#define ZOLW 'Z'
#define ANTYLOPA 'A'

//Rosliny
#define TRAWA '&'
#define MLECZ '@' 
#define GUARANA '#' 
#define WILCZE_JAGODY '%'
#define BARSZCZ_SOSNOWSKIEGO '$'

//INICJATYWA

#define CZLOWIEK_INICJATYWA 4

//Zwierzeta
#define WILK_INICJATYWA 5
#define OWCA_INICJATYWA 4
#define LIS_INICJATYWA 7
#define ZOLW_INICJATYWA 1
#define ANTYLOPA_INICJATYWA 4

//Rosliny
#define TRAWA_INICJATYWA 0
#define MLECZ_INICJATYWA 0 
#define GUARANA_INICJATYWA 0 
#define WILCZE_JAGODY_INICJATYWA 0
#define BARSZCZ_SOSNOWSKIEGO_INICJATYWA 0

//SILA

#define CZLOWIEK_SILA 5

//Zwierzeta
#define WILK_SILA 9
#define OWCA_SILA 4
#define LIS_SILA 3
#define ZOLW_SILA 2
#define ANTYLOPA_SILA 4

//Rosliny
#define TRAWA_SILA 0
#define MLECZ_SILA 0 
#define GUARANA_SILA 0 
#define WILCZE_JAGODY_SILA 99
#define BARSZCZ_SOSNOWSKIEGO_SILA 10

#define ZASIEG_RUCHU_DEFAULT 1

//NAZWA

#define CZLOWIEK_NAZWA "Czlowiek"

//Zwierzeta
#define WILK_NAZWA "Wilk"
#define OWCA_NAZWA "Owca"
#define LIS_NAZWA "Lis"
#define ZOLW_NAZWA "Zolw"
#define ANTYLOPA_NAZWA "Antylopa"

//Rosliny
#define TRAWA_NAZWA "Trawa"
#define MLECZ_NAZWA "Mlecz"
#define GUARANA_NAZWA "Guarana"
#define WILCZE_JAGODY_NAZWA "Jagody"
#define BARSZCZ_SOSNOWSKIEGO_NAZWA "Barszcz Sosnowskiego"

//ZASIEG RUCHU

#define ZASIEG_RUCHU_DEFAULT 1
#define ZASIEG_RUCHU_ANTYLOPY 2

//INNE 

#define ROZPRZESTRZENIANIE_ROSLIN 5 //Prawdopodobienstwo z jakim ROSLINA bedzie rozsiewac swoje nasiona w %
#define PROBY_ROZPRZESTRZENIENIA_MLECZA 3 //Ilosc prob, jakie podejmuje MLECZ, by sie rozprzestrzenic
#define PRAWDOPODOBIENSTWO_ZMIANY_POLOZENIA_ZOLWIA 25 //Prawdopodobienstwo z jakim ZOLW zmieni swoje polozenie w %
#define ZWIEKSZENIE_SILY_PRZY_ZJEDZENIU_GUARANY 3 //Zwierze, ktore zjadlo guarane zwieksza swoja sile o dana wartosc
#define MAKSYMALNA_SILA_PRZECIWNIKA_BY_ZOLW_ODBIL_ATAK 4 //Jesli przeciwnik ma mniejsz¹ si³ê ni¿ ta wartoœæ, to musi wrocic na swoje miejsce


//STRZA£KI

#define ESC 0x1b			
#define STRZA£KA_W_GORE 72		
#define STRZALKA_W_DOL 80
#define STRZALKA_W_PRAWO 77
#define STRZALKA_W_LEWO 75
#define ENTER 0x0d  

//KIERUNKI

#define GORA 0
#define PRAWO 1
#define DOL 2
#define LEWO 3

struct Wspolrzedne {
	int x;
	int y;
};