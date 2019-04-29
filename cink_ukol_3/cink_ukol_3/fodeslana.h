#ifndef FODESLANA_H
#define	FODESLANA_H

#include "faktura.h"
#include "stdafx.h"

class FakturaVydana : public Faktura {
private:

public:
	FakturaVydana(int cislo, float castka);
	void zauctuj(Ucet &ucet);
};

#endif

