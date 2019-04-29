/* 
 * File:   Faktura.h
 * Author: Filip Svoboda
 *
 * Created on 16. prosinec 2014, 23:30
 */

#ifndef FAKTURA_H
#define	FAKTURA_H

#include "Ucet.h"

class Faktura {
private:
    static int pocetFaktur;
    int cislo;
    float celkem;
public:
    Faktura(int cislo, float castka);
    ~Faktura();
    virtual void zauctuj(Ucet &ucet) = 0;
    float getCelkem();
    static int getPocetFaktur();
    int getCislo();
};

#endif	/* FAKTURA_H */

