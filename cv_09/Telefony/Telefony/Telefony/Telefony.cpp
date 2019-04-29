// Telefony.cpp : Defines the entry point for the console application.
// Vytvoøte program, který bude pracovat s jednoduchým telefonním seznamem osob.

#include "stdafx.h"

#define MAX 100

struct OSOBA {
	char jmeno[24];
	char prijmeni[35];
	char telefon[20];
};

OSOBA telsez[MAX];
int pocet = 0;

int vlozOsobu(void) {
	cout << "Zadej jmeno osoby: "; cin >> telsez[pocet].jmeno;
	cout << "Zadej prijmeni osoby: "; cin >> telsez[pocet].prijmeni;
	cout << "Zadej telefon osoby: "; cin >> telsez[pocet].telefon;
	pocet++;
	return 0;
}

int vlozOsobu(char *jm, char *pr, char *te) {
	strcpy_s(telsez[pocet].jmeno,jm);
	strcpy_s(telsez[pocet].prijmeni,pr);
	strcpy_s(telsez[pocet].telefon,te);
	pocet++;
	return 0;
}

int vypisOsob(void) {
	cout << "Telefonni seznam:\n";
	for (auto i = 0; i < pocet; i++) {
		cout << telsez[i].jmeno << " " << telsez[i].prijmeni << " " << telsez[i].telefon << endl;
	}
	return 0;
}

char jmenoSouboru[] = "Seznam.csv";

int main(int pocetSlov, char *slova[]) {
	FILE *soubor;
	errno_t chyba;
	char radek[81] = "";
	char jmeno[81];
	char prijmeni[81];
	char telefon[81];

	if (pocetSlov != 2) {
		cerr << "Chybne zadane parametry, spravne: telefony <jmeno souboru>\n";
		system("pause");
		return 1;
	}

	chyba = fopen_s(&soubor,slova[1],"r");
	if (chyba) {
		cerr << "Soubor " << slova[1] << " nejde otevrit\n";
		system("pause");
		return 2;

	}
	cout << "Cteni souboru: " << slova[1] << endl;
	if (fgets(radek, 80, soubor) == NULL) exit(1); // cte hlavicku souboru
	while (!feof(soubor)) {
		if (fgets(radek, 80, soubor) == NULL) break;
//		cout << radek << endl;
		char *ptr = radek;
		int i = 0;
		while (*ptr != ';') jmeno[i++] = *ptr++;
		jmeno[i] = '\0'; ptr++;
		i = 0;
		while (*ptr != ';') prijmeni[i++] = *ptr++;
		prijmeni[i] = '\0'; ptr++;
		i = 0;
		while (*ptr != '\n') telefon[i++] = *ptr++;
		telefon[i] = '\0'; 
//		cout << jmeno << " " << prijmeni << " " << telefon << endl;
		vlozOsobu(jmeno, prijmeni, telefon);
	}
/*
	vlozOsobu();
	vlozOsobu();
*/
	vypisOsob();
	cout << "Zadej jmeno: "; cin >> jmeno;
	cout << "Zadej prijmeni: "; cin >> prijmeni;
	for (int j = 0; j < pocet; j++) {
		if (!strcmp(telsez[j].jmeno, jmeno) && !(strcmp(telsez[j].prijmeni, prijmeni))) {
			strcpy_s(telefon, telsez[j].telefon);
			cout << telefon << endl;
			break;
		}
	}

	fclose(soubor);

	system("pause");
	return 0;
}

