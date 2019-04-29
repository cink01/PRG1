#ifndef FPRIJATA_H
#define	FPRIJATA_H

#include "Faktura.h"

class FakturaPrijata : public Faktura {
private:
public:
	FakturaPrijata(int cislo, float castka);
	void zauctuj(Ucet &ucet);
};

#endif	/* FAKTURAPRIJATA_H */

