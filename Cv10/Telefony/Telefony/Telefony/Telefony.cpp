// Telefony.cpp : Defines the entry point for the console application.
// Vytvoøte program, který bude pracovat s jednoduchým telefonním seznamem osob.

#include "stdafx.h"

#define MAX 100

class OSOBA {
	char jmeno[24];
	char prijmeni[35];
	char telefon[20];
public:
	OSOBA() {}
	OSOBA(char *jm, char *pr, char *tel) { 
		strcpy_s(jmeno, 23, jm);
		strcpy_s(prijmeni, 34, pr);
		strcpy_s(telefon, 19, tel);
	}
	char *getJmeno() { return jmeno; }
	void setJmeno(char *jm) { strcpy_s(jmeno,23,jm); }
	char *getPrijmeni() { return prijmeni; }
	void setPrijmeni(char *pr) { strcpy_s(prijmeni, 34, pr); }
	char *getTelefon() { return telefon; }
	void setTelefon(char *tel) { strcpy_s(telefon, 19, tel); }
};

OSOBA telsez[MAX];
int pocet = 0;

int vlozOsobu(void) {
	char jmeno[24];
	char prijmeni[35];
	char telefon[20];
	cout << "Zadej jmeno osoby: "; cin >> jmeno;
	cout << "Zadej prijmeni osoby: "; cin >> prijmeni;
	cout << "Zadej telefon osoby: "; cin >> telefon;
	telsez[pocet] = OSOBA(jmeno, prijmeni, telefon);
	pocet++;
	return 0;
}

int vlozOsobu(char *jm, char *pr, char *te) {
	telsez[pocet] = OSOBA(jm, pr, te);
	pocet++;
	return 0;
}

int vypisOsob(void) {
	cout << "Telefonni seznam:\n";
	for (auto i = 0; i < pocet; i++) {
		cout << telsez[i].getJmeno() << " " << 
				telsez[i].getPrijmeni() << " " << 
				telsez[i].getTelefon() << endl;
	}
	return 0;
};

int comp(const void *klic, const void *zaznam) {
	return strcmp((const char *)klic, ((OSOBA *)zaznam)->getPrijmeni());
};

int comp2(const void *prvni, const void *druhy) {
	return strcmp(((OSOBA *)prvni)->getPrijmeni(), ((OSOBA *)druhy)->getPrijmeni());
};

void hledejOsobu(void) {
	char prijmeni[35];
	OSOBA *ptr;

	//	cout << "Zadej jmeno: "; cin >> jmeno;
	cout << "Zadej prijmeni: "; cin >> prijmeni;

	if ((ptr = (OSOBA *)bsearch(prijmeni, telsez, pocet, sizeof(OSOBA), comp)) == 0) {
		cout << "Takovy zaznam neexistuje" << endl;
	}
	else {
		cout << ptr->getTelefon() << endl;
	}
};

class Polozka {
	char kod;
	char text[30];
public:
	Polozka() {}
	Polozka(char k, char *txt) : kod(k) { strcpy_s(text, 29, txt); }
	char *getPolozka() { 
		static char res[32]; res[0] = kod; res[1] = ':'; res[2] = '\0';
		strcat_s(res, 29, text);
		return res; 
	}
};

#define MAX_SIZE 5
Polozka Menu[MAX_SIZE] = { 
	Polozka('s', "hledej osobu"), 
	Polozka('e', "oprav osobu"), 
	Polozka('i', "vloz osobu"), 
	Polozka('d', "zrus osobu"), 
	Polozka('k', "konec") 
};

void zobrazMenu() {
	cout << "Menu:\n";
	for (auto i = 0; i < MAX_SIZE; i++) {
		cout << Menu[i].getPolozka() << endl;
	}
}

char volba() {
	char vol;
	cout << "Zadej volbu:"; cin >> vol;
	return vol;
}

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
	fclose(soubor);

	vypisOsob();
	qsort(telsez, pocet, sizeof(OSOBA), comp2);
	vypisOsob();

	char kod;
	do {
		zobrazMenu();
		kod = volba();
		switch (kod) {
			case 's': hledejOsobu(); break;
			case 'e': /* opravOsobu(); */ break;
			case 'i': vlozOsobu(); break;
			case 'd': /* zrusOsobu(); */ break;
			case 'k': goto konec;
		};
	} while (true);

	konec:

	ofstream vystup(slova[1]);
	cout << "Zapis do souboru: " << slova[1] << endl;

	vystup << "Jmeno;Prijmeni;Telefon\n";
	for (auto i = 0; i < pocet; i++) {
		vystup << telsez[i].getJmeno() << ";" << 
				  telsez[i].getPrijmeni() << ";" << 
			      telsez[i].getTelefon() << endl;
	}

	vystup.close();

	system("pause");
	return 0;
}
