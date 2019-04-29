/* 
 * File:   FakturaVydana.cpp
 * Author: Filip Svoboda
 * 
 * Created on 16. prosinec 2014, 23:33
 */

#include "FakturaVydana.h"

FakturaVydana::FakturaVydana(int cislo, float castka) : Faktura(cislo, castka) {
}

void FakturaVydana::zauctuj(Ucet &ucet) {
    ucet.vybrat(getCelkem());
}