#include "stdafx.h"
Ucet::Ucet():MAX_VKLAD(100000),MAX_VYBER(5000)
{
	prichozi = odchozi = 0; zustatek = pridat = odebrat= 0;
}
//Ucet::Ucet(): MAX_VKLAD(100000), MAX_VYBER(5000)
void Ucet::vlozit(float castka) {
	if (castka > MAX_VKLAD)
		cout << "Zadana castka prekracuje limit pro maximlani povoleny vklad.\n";
	if (castka < 0)
		cout<<"Prosim kladna cisla.\n";
	zustatek = getZustatek();

	zustatek += castka;
	prichozi++;
	pridat += castka;
}
void Ucet::vybrat(float castka) {
	if (castka > MAX_VYBER || castka > zustatek || castka < 0)
		cout<<"Nelze vybrat zadanou castku\n";
	zustatek -= castka;
	odchozi++;
	odebrat += castka;
}
void Ucet::vypisinfo() {
	cout << "Cislo uctu: " << cu << " Majitel: " << jmeno << " " << prijmeni << "Zustatek: " << zustatek
		<< "Celkovy pocet vkladu: " << prichozi << "Celkovy pocet vyberu: " << odchozi
		<< "Celkem vlozeno penez: " << pridat << "Celkem vybrano penez : " << odebrat
		<< endl;
}

void Ucet::stavuctu() {
	cout << "Zustatek: " << zustatek << "Celkovy pocet vkladu: " << prichozi
		<< "Celkovy pocet vyberu: " << odchozi << "Celkem vlozeno penez: " << pridat
		<< "Celkem vybrano penez : " << odebrat << endl;
}

