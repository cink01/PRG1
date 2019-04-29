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
bool nulove(int&a, int&b) {
	if (a == 0 || b == 0) return true;
	return false;
}
void obenula(int&a, int&b) {
	if (a == 0 && b == 0) cout << "Obe cisla jsou nula: Ano\n";
	else cout << "Obe cisla jsou nula: Ne\n";
}
void rozdil(int&a, int&b) {
	cout << "Rozdil je: " << a - b << endl;
}
void soucin(int&a, int&b) {
	cout << "Soucin je: " << a * b << endl;
}
void celopodil(int&a, int&b) {
	if (b != 0) cout << "Celociselny podil je: " << a / b << endl;
	else cout << "Celociselny podil je: Nulou nelze delit!\n";
}
void podil(int&a, int&b) {
	if (b != 0) printf_s("Podil je: %.2f \n", ((float)a / b));
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
	if (a == 0 || b == 0) nulove(a, b);
	else {
		int r = 0;
		do {
			r = a % b;
			a = b;
			b = r;
		} while (b != 0);
		return a;
	}
}
void lcm(int a, int b) {
	cout << "nejmensi spolecny nasobek je: " << a*b / gcd(a, b) << endl;
}