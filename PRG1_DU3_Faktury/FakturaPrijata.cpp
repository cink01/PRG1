/* 
 * File:   FakturaPrijata.cpp
 * Author: Filip Svoboda
 * 
 * Created on 16. prosinec 2014, 23:34
 */

#include "FakturaPrijata.h"

FakturaPrijata::FakturaPrijata(int cislo, float castka) : Faktura(cislo, castka) {
}

void FakturaPrijata::zauctuj(Ucet &ucet) {
    ucet.vlozit(getCelkem());
}