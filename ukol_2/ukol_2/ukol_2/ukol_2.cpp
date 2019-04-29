// Telefony.cpp : Defines the entry point for the console application.
// Vytvoøte program, který bude pracovat s jednoduchým telefonním seznamem osob.

#include "stdafx.h"

#define MAX 100
int const MAX_VYBER = 5000;
int const MAX_VKLAD = 100000;

class ACC {
	char jmeno[30];
	char prijmeni[35];
	char cu[7];
	int prichozi;
	int odchozi;
	float zustatek;
	float vklad, vyber;
public:
	ACC() { prichozi = odchozi = 0; zustatek = vklad = vyber = 0; }
	ACC(char *jm, char *pr, char *cu) {
		strcpy_s(jmeno, 29, jm);
		strcpy_s(prijmeni, 34, pr);
		strcpy_s(cu, 6, cu);
		prichozi = odchozi = 0;
		zustatek =  vklad = vyber = 0;
	}
	ACC(char *jm, char *pr, char *cu, float &zus, float &vkl, float&vyb, int &pri,int &odc) {
		strcpy_s(jmeno, 29, jm);
		strcpy_s(prijmeni, 34, pr);
		strcpy_s(cu, 6, cu);
		this->zustatek = zus;
		this->prichozi = pri;
		this->vklad = vkl;
		this->vyber = vyb;
		this->odchozi = odc;
	}
	char *getJmeno() { return jmeno; }
	void setJmeno(char *jm) { strcpy_s(jmeno, 29, jm); }
	char *getPrijmeni() { return prijmeni; }
	void setPrijmeni(char *pr) { strcpy_s(prijmeni, 34, pr); }
	char *getCu() { return cu; }
	void setCu(char *cu) { strcpy_s(cu, 6, cu); }
	int getPrichozi() { return prichozi; };
	int getOdchozi() { return odchozi; };
	float getVklad() { return vklad; }
	float getVyber() { return vyber; }
	float *getZustatek() { return &zustatek; }
	//void addPrihozi() { this->prichozi++; }
	//void addOdhozi() { this->odchozi++; }
	//void addZustatek(float addplus) { this->zustatek += addplus; }
	//void minusZustat(float addminus) { this->zustatek += addminus; }
	void addVklad(float addplus) {
		if (addplus > MAX_VKLAD)
			cout<< "Zadana castka prekracuje limit pro maximlani povoleny vklad.";
		if (addplus < 0)
			cout<< "Prosim kladna cisla.";
		this->zustatek += addplus; this->vklad += addplus; this->prichozi++;}
	void addVyber(float addminus) {
		if (addminus > MAX_VYBER || addminus > zustatek || addminus < 0)
			cout<< "Nelze vybrat zadanou castku";
		this->zustatek -= addminus; this->vyber += addminus; this->odchozi++;}
};
/*
ACC accsez[MAX];
int pocet = 0;
*/
int vlozOsobu(void) {
	char jmeno[30];
	char prijmeni[35];
	char cu[7];
	cout << "Zadej jmeno osoby: "; cin >> jmeno;
	cout << "Zadej prijmeni osoby: "; cin >> prijmeni;
	cout << "Zadej cislo uctu: "; cin >> cu;
	accsez[pocet] = ACC(jmeno, prijmeni, cu);
	pocet++;
	return 0;
}

int vlozOsobu(char *jm, char *pr, char *te) {
	accsez[pocet] = ACC(jm, pr, te);
	pocet++;
	return 0;
}

int vlozOsobu(char *jm, char *pr, char *cu,float &zus, float &vkl, float&vyb, int &pri, int &odc) {
	accsez[pocet] = ACC(jm, pr, cu, zus, vkl, vyb, pri,odc);
	pocet++;
	return 0;
}

int vypisOsob(void) {
	cout << "----------------------------------------\n";
	cout << "	 seznam uctu:\n";
	cout << "----------------------------------------\n";
	for (auto i = 0; i < pocet; i++) {
		cout <<accsez[i].getJmeno() << " " <<
			accsez[i].getPrijmeni() << " " << 
			accsez[i].getCu() << " " <<
			accsez[i].getZustatek() << " " <<
			accsez[i].getVyber() << " " <<
			accsez[i].getVklad() << " " <<
			accsez[i].getPrichozi() << " " <<
			accsez[i].getOdchozi()<< endl;
	}
	cout << "----------------------------------------\n";
	return 0;
};

int comp(const void *klic, const void *zaznam) {
	return strcmp((const char *)klic, ((ACC *)zaznam)->getPrijmeni());
};

int comp2(const void *prvni, const void *druhy) {
	return strcmp(((ACC *)prvni)->getPrijmeni(), ((ACC *)druhy)->getPrijmeni());
};
void sort(void) { qsort(accsez, pocet, sizeof(ACC), comp2); }
void hledejOsobu(void) {
	char cu[7];
	ACC *ptr;
	cout << "Zadej cislo uctu: "; cin >> cu;
	if ((ptr = (ACC *)bsearch(cu, accsez, pocet, sizeof(ACC), comp)) == 0) {
		cout << "Takovy zaznam neexistuje" << endl;
	}
	else {
		cout << ptr->getJmeno() << ptr->getPrijmeni() << ptr->getCu()<< ptr->getZustatek<< endl;
	}
};

void opravOsobu(void) {
	char jmeno[30];
	char prijmeni[35];
	char cu[7];
	ACC *ptr;

	//	cout << "Zadej jmeno: "; cin >> jmeno;
	cout << "Zadej cislo uctu: "; cin >> cu;

	if ((ptr = (ACC *)bsearch(cu, accsez, pocet, sizeof(ACC), comp)) == 0) {
		cout << "Takovy zaznam neexistuje" << endl;
	}
	else {
		cout << "Zadej nove jmeno: "; cin >> jmeno;
		cout << "Zadej nove prijmeni: "; cin >> prijmeni;
		ptr->setJmeno(jmeno);
		ptr->setPrijmeni(prijmeni);
		cout << "Nastaveno " << endl;
	}
};

void zrusOsobu(void) {
	char cu[7];
	ACC *ptr;
	cout << "Zadej cislo uctu: "; cin >> cu;
	if ((ptr = (ACC *)bsearch(cu, accsez, pocet, sizeof(ACC), comp)) == 0) {
		cout << "Takovy zaznam neexistuje" << endl;
	}
	else {
		memmove((void*)ptr, (void*)((char *)ptr + sizeof(ACC)), (char *)(&accsez[pocet]) - ((char *)ptr + (sizeof(ACC))));
		pocet--;
	}
};
/*
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

#define MAX_SIZE 10
class MENU {
	Polozka Menu[MAX_SIZE];
	int pocetPolozek;
public:
	MENU() {};
	void pridejPolozku(Polozka p) {};
	void zobrazMenu() {};
	char vyberVolbu() {};
};
Polozka Menu[MAX_SIZE] = {
	Polozka('0', "konec"),
	Polozka('1', "hledej osobu"),
	Polozka('2', "oprav osobu"),
	Polozka('3', "vloz osobu"),
	Polozka('4', "zrus osobu"),
	Polozka('5', "konec")
};

void MENU::zobrazMenu() {
	cout << "----------------Menu-----------------\n";
	for (auto i = 0; i < MAX_SIZE; i++) {
		cout << Menu[i].getPolozka() << " " << endl;
	}
}

char volba() {
	char vol;
	cout << "Zadej volbu:"; cin >> vol;
	return vol;
}

*/
int main(int pocetSlov, char *slova[]) {
	FILE *soubor;
	errno_t chyba;
	char radek[60] = "";
	char jmeno[60];
	char prijmeni[60];
	char cu[7];
	float addplus,addminus,zus,vyb,vkl;
	int pri, odc;

	if (pocetSlov != 2) {
		cerr << "Chybne zadane parametry, spravne: ucty <jmeno souboru>\n";
		system("pause");
		return 1;
	}

	chyba = fopen_s(&soubor, slova[1], "r");
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
		while (*ptr != '\n') cu[i++] = *ptr++;
		cu[i] = '\0';
		i = 0;
		while (*ptr != '\n') accsez[i++].getZustatek = *ptr++;
		accsez[i].getZustatek = '\0';
		i = 0;
		/*while (*ptr != '\n') cu[i++] = *ptr++;
		cu[i] = '\0';
		i = 0;
		while (*ptr != '\n') cu[i++] = *ptr++;
		cu[i] = '\0';
		i = 0;
		while (*ptr != '\n') cu[i++] = *ptr++;
		cu[i] = '\0';
		i = 0;
		while (*ptr != '\n') cu[i++] = *ptr++;
		cu[i] = '\0';*/
		
		vlozOsobu(jmeno, prijmeni, cu, zus, vkl,vyb,pri,odc);
	}
	fclose(soubor);

	int volba;
	do {
		switch (volba) {
		case '0':  goto konec;
		case '1': opravOsobu(); sort(); break;
		case '2': vlozOsobu(); sort();  break;
		case '3': zrusOsobu(); break;
		case '4':sort(); vypisOsob(); break;
		};
	} while (true);

konec:

	ofstream vystup(slova[1]);
	cout << "Zapis do souboru: " << slova[1] << endl;

	vystup << "Jmeno;Prijmeni;Telefon\n";
	for (auto i = 0; i < pocet; i++) {
		vystup << accsez[i].getJmeno() << ";" <<
			accsez[i].getPrijmeni() << ";" <<
			accsez[i].getCu() << endl;
	}

	vystup.close();

	system("pause");
	return 0;
}
