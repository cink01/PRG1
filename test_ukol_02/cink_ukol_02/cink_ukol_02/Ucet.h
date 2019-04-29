#include "stdafx.h"
class Ucet
{
private:
	int const MAX_VKLAD;
	int const MAX_VYBER;
	char jmeno[30];
	char prijmeni[40];
	char cu[7];
	float zustatek;
	float pridat;
	float odebrat;
	int prichozi;
	int odchozi;
public:
	Ucet();
	//Ucet(char *jm, char *pr, char *cu, float &zus, float &prid, float &odeb, int &prich, int &odch);
	char *getJmeno() { return jmeno; }
	void setJmeno(char *jm) { strcpy_s(jmeno, 29, jm); }
	char *getPrijmeni() { return prijmeni; }
	void setPrijmeni(char *pr) { strcpy_s(prijmeni, 34, pr); }
	char *getCu() { return cu; }
	void setCu(char *cu) { strcpy_s(cu, 6, cu); }
	int getPrichozi() { return prichozi; };
	int getOdchozi() { return odchozi; };
	float getVklad() { return pridat; }
	float getVyber() { return odebrat; }
	float getZustatek() { return zustatek; }
	int getMax() { return MAX_VKLAD; }
	int getMin() { return MAX_VYBER; }
	void vlozit(float castka);
	void vybrat(float castka);
	void vypisinfo();
	void stavuctu();
};


