#ifndef UCET_H
#define	UCET_H

#include "stdafx.h"

class Ucet {
private:
	const int MAX_VYBER;
	const int MAX_VKLAD;
	string jmeno;
	string prijmeni;
	string cu;
	float zustatek;
	int usepsneVybery;
	int uspesneVklady;
	float prichoziPlatby;
	float odchoziPlatby;
public:
	Ucet(string jmeno, string prijmeni, string cu);
	Ucet();
	friend ostream& operator <<(ostream& os, Ucet &u);
	friend istream& operator >> (istream& is, Ucet &u);
	string getStavString();
	string getInfoString();
	void vlozit(float castka);
	void vybrat(float castka);
	string getJmeno() { return jmeno; }
};



#endif	/* UCET_H */

