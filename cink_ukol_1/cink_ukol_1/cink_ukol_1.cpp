// cink ukol c.1
// predelat nulovy cisla na bool kvuli lcm a gcd
#include "stdafx.h"

int main()
{
	int a, b;
	cout << "\tVitejte v programu\nPocitame s celymi cisly\nZadejte cisla,se kterymi chcete pocitat\n";
	cout << "----------------------------------------\n";
	cout << "\tZadejte 1. cislo: "; cin >> a;
	cout << "\tZadejte 2. cislo: "; cin >> b;
	cout << "----------------------------------------\n";
	suma(a, b);
	max(a, b);
	average(a, b);
	if (nulove(a, b) == false && gcd(a, b) != 1) {
		cout << "Jedno z cisel je nula: Ne\n";
		lcm(a, b);
		if (gcd(a, b) == 1) cout << "Nejvetsi spolecny delitel je: Neexistuje(" << gcd(a, b) << ")\n";
		else cout << "Nejvetsi spolecny delitel je: " << gcd(a, b) << endl;
	}
	if (nulove(a, b) == false && gcd(a, b) == 1) {
		cout << "Nejvetsi spolecny delitel je: Neexistuje(" << gcd(a, b) << ")\n";
		lcm(a, b);
	}
	if (nulove(a,b) == true){
		cout << "Jedno z cisel je nula: Ano\n";
		cout << "Nejvetsi spolecny delitel je: -\n";//nema smysl delat protoze je jen 1 cislo nenulove;
		cout << "Nejmensi spolecny nasobek je: -\n";

	}
	obenula(a, b);
	rozdil(a, b);
	soucin(a, b);
	podil(a, b);
	stejna(a, b);
	min(a, b);
	vetsineznula(a, b);
	opak(a);
	cout << "----------------------------------------\n";
	int c;
	cout << "Vyberte si nejakou funkci naseho programu \n\nZadejte cislo podle nabidky\n----------------------------------------\n 1 ... soucet\n 2 ... rozdil\n 3 ... soucin\n 4 ... podil celociselny\n 5 ... maximum\n 6 ... minimum\n----------------------------------------\n";
	cout << "Zadejte vyber(paklize vyberete jine cislo nez (1-6) program bude ukoncen): "; cin >> c;
	cout << "--------------------------------------------------------------------------------\n";
	while (c >= 1 && c <= 6) {
		cout << "Zvolili jste: " << c << endl;
		switch (c)
		{
		case 1:
			suma(a, b);
			break;
		case 2:
			rozdil(a, b);
			break;
		case 3:
			soucin(a, b);
			break;
		case 4:
			celopodil(a, b);
			break;
		case 5:
			max(a, b);
			break;
		case 6:
			min(a, b);
			break;
		default: cout << "Zadejte cislo pouze z nabidky nebo zadejte 0 pro ukonceni vyberu\n";
			}
		cout << "--------------------------------------------------------------------------------\n";
		cout << "Zadejte vyber(paklize vyberete jine cislo nez (1-6) program bude ukoncen): "; cin >> c;
		cout << "--------------------------------------------------------------------------------\n";
	}
	cout << "Zvolili jste: "<<c<<" \nCislo neni v nabidce\n Program bude ukoncen\n";
	system("pause");
    return 0;
}

