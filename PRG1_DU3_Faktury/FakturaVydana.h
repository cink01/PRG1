/* 
 * File:   FakturaVydana.h
 * Author: Filip Svoboda
 *
 * Created on 16. prosinec 2014, 23:33
 */

#ifndef FAKTURAVYDANA_H
#define	FAKTURAVYDANA_H

#include "faktura.h"

class FakturaVydana : public Faktura {
private:
        
public:
    FakturaVydana(int cislo, float castka);
    void zauctuj(Ucet &ucet);
};

#endif	/* FAKTURAVYDANA_H */

