/* 
 * File:   FakturaPrijata.h
 * Author: Filip Svoboda
 *
 * Created on 16. prosinec 2014, 23:34
 */

#ifndef FAKTURAPRIJATA_H
#define	FAKTURAPRIJATA_H

#include "Faktura.h"

class FakturaPrijata : public Faktura {
private:
public:
    FakturaPrijata(int cislo, float castka);
    void zauctuj(Ucet &ucet);
};

#endif	/* FAKTURAPRIJATA_H */

