#include "stdafx.h"
int main(int argc, char** argv) {
	cout << "Vitejte v ucetnim programu \n";
	int volba;
	char jm[30]="TOm";
	char pr[40]="cink";
	char cu[7]="111111";
/*	char *j=jm;
	char *p=pr;
	char *c=cu;
	float zus;
	float prid;
	float odeb;
	int prich;
	int odch;*/
	float castka;
	Ucet u;
	//Ucet ucet(char *jm, char *pr, char *cu, float &zus, float &prid, float &odeb, int &prich, int &odch);
	u.setJmeno(jm);
	u.setPrijmeni(pr);
	u.setCu(cu);
	
	do{
		cin >> volba;
		cout << "------------------------\n";
		cout << "Menu programu Ucet\n" << endl;
		cout << "------------------------\n";
		cout << "'0' Konec programu" << endl;
		cout << "'1' Výpis stavu úètu" << endl;
		cout << "'2' Výpis informací o úètu" << endl;
		cout << "'3' Uložit èástku na vybraný úèet" << endl;
		cout << "'4' Vybrat èástku z úètu" << endl;
		cout << "------------------------\n";
		cout << "Zvolte volbu: " << endl;

		cin >> volba;
		switch(volba) {
		case '1': u.stavuctu(); break;
		case '2': u.vypisinfo(); break;
		case '3': cin>>castka; u.vlozit(castka); break;
		case '4': cin >> castka; u.vybrat(castka); break;
		}
	} while (volba != 0);
	cout << "preji pekny den" << endl;
return 0;
}

