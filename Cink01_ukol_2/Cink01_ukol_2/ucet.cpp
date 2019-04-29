/*#include "stdafx.h"
Ucet::Ucet() :MAX_VKLAD(100000), MAX_VYBER(5000)
{
	prichozi = odchozi = 0; zustatek = pridat = odebrat = 0;
}
Ucet::Ucet(string jm, string pr, string cu)
{
	this->jmeno = jm;
	this->prijmeni = prijmeni;
	this->cuctu = cu;/*
	this->zustatek = zus;
	this->pridat = prid;
	this->odebrat = odeb;
	this->prichozi= prich;
	this->odchozi = odch;
}
void Ucet::vlozit(float castka) {
	if (castka > MAX_VKLAD)
		cout << "Zadana castka prekracuje limit pro maximlani povoleny vklad.\n";
	if (castka < 0)
		cout << "Prosim kladna cisla.\n";
	zustatek = getZustatek();

	zustatek += castka;
	prichozi++;
	pridat += castka;
}
void Ucet::vybrat(float castka) {
	if (castka > MAX_VYBER || castka > zustatek || castka < 0)
		cout << "Nelze vybrat zadanou castku\n";
	zustatek -= castka;
	odchozi++;
	odebrat += castka;
}
void Ucet::vypisinfo() {
	cout << "Cislo uctu: " << this->cuctu << " Majitel: " << this->jmeno << " " << this->prijmeni << "Zustatek: " << this->zustatek
		<< "Celkovy pocet vkladu: " << this->prichozi << "Celkovy pocet vyberu: " << this->odchozi
		<< "Celkem vlozeno penez: " << this->pridat << "Celkem vybrano penez : " << this->odebrat
		<< endl;
}

void Ucet::stavuctu() {
	cout << "Zustatek: " << this->zustatek << "Celkovy pocet vkladu: " << this->prichozi
		<< "Celkovy pocet vyberu: " << this->odchozi << "Celkem vlozeno penez: " << this->pridat
		<< "Celkem vybrano penez : " << this->odebrat << endl;
}
*/