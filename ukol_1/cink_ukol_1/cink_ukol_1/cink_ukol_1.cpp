// cink_ukol_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void suma(int&a, int&b) {
	cout << "Soucet je: " << a + b << endl;
}
void max(int&a, int&b) {
	if (a >= b)cout << "Vetsi cislo ze je: " << a << endl;
	else cout << "Vetsi cislo ze je: " << b << endl;
}
void min(int&a, int&b) {
	if (a >= b)cout << "Mensi cislo ze je: " << b << endl;
	else cout << "Mensi cislo ze je: " << a << endl;
}
void average(int&a, int&b) {
	printf_s("Prumer je: %.2f \n", (((float)a + b) / 2));
}
int minspolnas(int&a, int&b) {
	return 0;
}
int maxspoldel(int&a, int&b) {
	return 0;
}
void nulove(int&a, int&b) {
	if (a == 0 || b == 0) cout << "Jedno z cisel je nula: Ano\n";
	else cout << "Jedno z cisel je nula: Ne\n";
}
void obenula(int&a, int&b) {
	if (a == 0 && b == 0) cout<<"Obe cisla jsou nula: Ano\n";
	else cout << "Obe cisla jsou nula: Ne\n";
}
void rozdil(int&a, int&b) {
	cout << "Rozdil je: " << a - b << endl;
}
void soucin(int&a, int&b) {
	cout << "Soucin je: " << a * b << endl;
}
void celopodil(int&a, int&b) {
	if (b != 0) cout << "Celociselny podil je: "<<a/b<<endl;
	else cout << "Celociselny podil je: Nulou nelze delit!\n";
}
void podil(int&a, int&b) {
	if(b!=0) printf_s("Podil je: %.2f \n", ((float)a / b));
	else cout << "Podil je: Nulou nelze delit!\n";
}
void stejna(int&a, int&b) {
	if (a == b)cout << "Cisla jsou stejna: Ano\n";
	else cout << "Cisla jsou stejna: Ne\n";
}
void vetsineznula(int&a, int&b) {
	if (a>0 && b>0)cout << "Obe cisla jsou vetsi nez 0: Ano\n";
	else cout << "Obe cisla jsou vetsi nez 0: Ne\n";
}
void opak(int&a) {
	cout << "Opacne cislo k " << a << " je: " << -a << endl;
}
int gcd(int a, int b) {
	if (a < 1 || b < 1)	printf_s("a nebo b je mensi nez 1\n");
	int r = 0;
	do{
		r = a % b;
		a = b;
		b = r;
	}while (b != 0);
	return a;
}
void lcm(int a, int b) {
	cout << "nejmenci spolecny nasobek je: " << a*b / gcd(a, b)<<endl;
}
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
	lcm(a, b);
	if (gcd(a, b) == 1)cout << "Nejvetsi spolecny delitel je: Neexistuje(" << gcd(a, b) << ")\n";
	else cout << "Nejvetsi spolecny delitel je: " << gcd(a, b) << endl;
	nulove(a, b);
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

