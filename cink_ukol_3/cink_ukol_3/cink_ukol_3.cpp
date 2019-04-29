#include "stdafx.h"

const int MAX_FAKTUR = 150;
const int POC_STAV_UCTU = 5000;        // max 100 000

int menu() {
	cout << "0. Konec programu\n";
	cout << "1. Zalozit fakturu\n";
	cout << "2. Zauctovat fakturu\n";
	cout << "3. Vypis vydanych faktur\n";
	cout << "4. Vypis prijatych faktur\n";
	cout << "5. Vypis vsech faktur\n";

	int volba;

	do {
		volba = getch() - '0';
		//cin >> volba;
		if (!(volba >= 0 && volba <= 5))
			cout << "Neplatna volba\n";
	} while (!(volba >= 0 && volba <= 5));

	system("cls");

	return volba;
}

bool exist(int cislo, Faktura *faktury[]) {
	for (int i = 0; i < MAX_FAKTUR; i++)
		if (faktury[i] != NULL && faktury[i]->getCislo() == cislo)
			return true;

	return false;
}

void zalozitFakturu(Faktura *faktury[]) {
	if (Faktura::getPocetFaktur() == MAX_FAKTUR) {
		cout << "Doshali jste maximalniho poctu faktur.";
		return;
	}

	cout << "1. Prijata faktura\n";
	cout << "2. Vydana faktura\n";

	int volba;
	int cislo;
	float castka;

	do {
		volba = getch() - '0';
		//cin >> volba;
	} while (!(volba >= 1 && volba <= 2));

	do {
		cout << "Cislo faktury: ";
		cin >> cislo;
		if (exist(cislo, faktury))
			cout << "Faktura se zadanym cislem jiz existuje.\n";
	} while (exist(cislo, faktury));

	cout << "Castka: ";
	cin >> castka;

	for(int i = 0; i < MAX_FAKTUR; i++) {
		if (faktury[i] == NULL) {
			if (volba == 1)
				faktury[i] = new FakturaPrijata(cislo, castka);
			else
				faktury[i] = new FakturaVydana(cislo, castka);
			break;
		}
	}

	cout << "Faktura byla uspesne zalozena";
}

void zauctovatFakturu(Faktura *faktury[], Ucet &ucet) {
	int cislo;
	cout << "Zadjte cislo faktury, kterou chcete zauctovat: ";
	cin >> cislo;

	if (!exist(cislo, faktury)) {
		cout << "Zadana faktura neexistuje.\n";
		return;
	}

	try {
		for (int i = 0; i < MAX_FAKTUR; i++)
			if (faktury[i]->getCislo() == cislo) {
				faktury[i]->zauctuj(ucet);
				break;
			}
		cout << "Faktura byla uspesne zauctovana.";
	}
	catch (const char *e) {
		cout << e;
	}
}

void vypsatVydane(Faktura *faktury[]) {
	for (int i = 0; i < MAX_FAKTUR; i++) {
		if ((dynamic_cast<FakturaVydana*>(faktury[i])) != NULL) {
			cout << "cislo faktury: " << faktury[i]->getCislo() << endl;
			cout << "castka: " << faktury[i]->getCelkem() << endl << endl;
		}
	}
}

void vypsatPrijate(Faktura *faktury[]) {
	for (int i = 0; i < MAX_FAKTUR; i++) {
		if ((dynamic_cast<FakturaPrijata*>(faktury[i])) != NULL) {
			cout << "cislo faktury: " << faktury[i]->getCislo() << endl;
			cout << "castka: " << faktury[i]->getCelkem() << endl << endl;
		}
	}
}

void vypsatVse(Faktura *faktury[]) {
	for (int i = 0; i < MAX_FAKTUR; i++)
		if (faktury[i] != NULL) {
			cout << "cislo faktury: " << faktury[i]->getCislo() << endl;
			cout << "castka: " << faktury[i]->getCelkem() << endl << endl;
		}
}

void pressAnyButton() {
	cout << "\nPokracujte stisknutim libovolneho tlacitka\n";
	getch();
	system("cls");
}

int main(int argc, char** argv) {
	int volba;
	Ucet ucet;
	ucet.vlozit(POC_STAV_UCTU);
	Faktura *faktury[MAX_FAKTUR];

	for (int i = 0; i < MAX_FAKTUR; i++)
		faktury[i] = NULL;

	do {
		volba = menu();
		switch (volba) {
		case 0:
			break;
		case 1:
			zalozitFakturu(faktury);
			pressAnyButton();
			break;
		case 2:
			zauctovatFakturu(faktury, ucet);
			pressAnyButton();
			break;
		case 3:
			vypsatVydane(faktury);
			pressAnyButton();
			break;
		case 4:
			vypsatPrijate(faktury);
			pressAnyButton();
			break;
		case 5:
			vypsatVse(faktury);
			pressAnyButton();
			break;
		default: break;
		}
	} while (volba != 0);


	for (int i = 0; i < MAX_FAKTUR; i++) {
		delete faktury[i];
		faktury[i] == NULL;
	}

	return 0;
}

