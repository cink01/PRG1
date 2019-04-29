// Cink01_ukol_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
const int MAX = 109999;
const int MIN = 100001;
class Ucet
{
private:
	int const MAX_VKLAD;
	int const MAX_VYBER;
	string jmeno;
	string prijmeni;
	int cuctu;
	float zustatek;
	float pridat;
	float odebrat;
	int prichozi;
	int odchozi;
public:
	Ucet();
	Ucet(int cu, string jm, string pr);
	Ucet(int cu, string jm, string pr, float zus, float pri, float ode, int prich, int odch);
	/*string getJmeno() { return jmeno; }
	void setJmeno(string jm) { this->jmeno = jm; }
	string getPrijmeni() { return prijmeni; }
	void setPrijmeni(string pr) { this->prijmeni = pr; }
	long int getCu() { return cuctu; }
	void setCuctu(long int cu) { this->cuctu = cu; }
	int getPrichozi() { return prichozi; };
	int getOdchozi() { return odchozi; };
	float getVklad() { return pridat; }
	float getVyber() { return odebrat; }*/
	float getZustatek() { return zustatek; }
	int getMax() { return MAX_VKLAD; }
	int getMin() { return MAX_VYBER; }
	void vlozit(float castka);
	void vybrat(float castka);
	void vypisinfo();
	void stavuctu();
};
Ucet::Ucet() :MAX_VKLAD(100000), MAX_VYBER(5000)
{
	prichozi = odchozi = 0; zustatek = pridat = odebrat = 0;
}
Ucet::Ucet(int cu, string jm, string pr) : MAX_VKLAD(100000), MAX_VYBER(5000) {
	this->jmeno = jm;
	this->prijmeni = pr;
	this->cuctu = cu;
	prichozi = odchozi = 0; zustatek = pridat = odebrat = 0;
}
Ucet::Ucet(int cu, string jm, string pr, float zus, float pri, float ode, int prich, int odch) : MAX_VKLAD(100000), MAX_VYBER(5000) {
	this->jmeno = jm;
	this->prijmeni = pr;
	this->cuctu = cu;
	this->zustatek = zus;
	this->pridat = pri;
	this->odebrat = ode;
	this->prichozi= prich;
	this->odchozi = odch;

}
void Ucet::vlozit(float castka) {
	if (castka > MAX_VKLAD|| castka < 0)
		cout << "Zadana castka prekracuje limit(nebo je zaporny) pro maximlani povoleny vklad.\n"; 
	else{
		zustatek = getZustatek();
		zustatek += castka;
		prichozi++;
		pridat += castka;
	}
}
void Ucet::vybrat(float castka) {
	if (castka > MAX_VYBER || castka > zustatek || castka < 0)
		cout << "Nelze vybrat zadanou castku\n";
	else{
		zustatek -= castka;
		odchozi++;
		odebrat += castka;
	}
}
void Ucet::vypisinfo() {
	cout << "Cislo uctu: " << this->cuctu << " Majitel: " << this->jmeno << " " << this->prijmeni << " Zustatek: " << this->zustatek<<endl
		<< " Celkovy pocet vkladu: " << this->prichozi << " Celkovy pocet vyberu: " << this->odchozi<<endl
		<< " Celkem vlozeno penez: " << this->pridat << " Celkem vybrano penez : " << this->odebrat
		<< endl;
}

void Ucet::stavuctu() {
	cout << "Zustatek: " << this->zustatek <<endl <<"Celkovy pocet vkladu: " << this->prichozi
		<< " Celkovy pocet vyberu: " << this->odchozi <<endl<< "Celkem vlozeno penez: " << this->pridat
		<< " Celkem vybrano penez : " << this->odebrat << endl;
}
void menu() {
	cout << "\n---------------------------\n";
	cout << "	Menu programu Ucet";
	cout << "\n---------------------------\n";
	cout << "'0' Konec programu" << endl;
	cout << "'1' Vypis stavu uctu" << endl;
	cout << "'2' Vypis informaci o uctu" << endl;
	cout << "'3' Ulozit castku na vybrany ucet" << endl;
	cout << "'4' Vybrat castku z uctu" << endl;
	cout << "------------------------\n";
	cout << "Zvolte volbu: " << endl;
}

int main(int pocetSlov, char *slova[])
{
	FILE *soubor;
	int volba;
	string jm, pr;
	int cu;
	float zus, pri, ode;
	int add, min;
	float castka;

	if (pocetSlov == 2) {
		ifstream fin;
		fin.open(slova[1]);
		if (fin.is_open())
		{
			fin >> cu >> jm >> pr >> zus >> pri >> ode >> add >> min;
			fin.close();
		}
		Ucet ucet(cu, jm, pr, zus, pri, ode, add, min);
		do {
			menu();
			cin >> volba;
			if (volba < 0 || volba>4)
				cout << "Zadany chybny parametr. prosim opakujte. ";
			switch (volba){
				case 1: ucet.stavuctu(); break;
				case 2: ucet.vypisinfo(); break;
				case 3: cout << "zadejte castku, kterou chtete vlozit: "; cin >> castka; ucet.vlozit(castka); break;
				case 4: cout << "zadejte castku, kterou chtete vybrat: "; cin >> castka; ucet.vybrat(castka); break;
				}
			} while (volba != 0);
	}
	cout << "Vitejte v ucetnim programu \n";
	cout << "------------------------------\n";
	if (pocetSlov == 1)
	{
		cout << "Zadejte jmeno: ";
		cin >> jm;
		cout << "Zadejte prijmeni: ";
		cin >> pr;
		cout << "Zadejte cislo uctu(v rozmezi(100001 - 109999): "; cin >> cu;
		cout<<" \npaklize zadate spatne, bude vam prideleno automaticky" << endl;
		
		if ((cu < MIN) || (cu > MAX))
			cu = 100001;
		Ucet ucet(cu, jm, pr);
		do {
			menu();
			cin >> volba;
			if (volba < 0 || volba>4)
				cout << "Zadany chybny parametr. prosim opakujte. ";
			switch (volba)
			{
			case 1: ucet.stavuctu(); break;
			case 2: ucet.vypisinfo(); break;
			case 3: cout << "zadejte castku, kterou chtete vlozit: "; cin >> castka; ucet.vlozit(castka); break;
			case 4: cout << "zadejte castku, kterou chtete vybrat: "; cin >> castka; ucet.vybrat(castka); break;
			}
		} while (volba != 0);
	}

	system("pause");
	return 0;
}

