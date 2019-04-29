/* 
 * File:   Faktura.cpp
 * Author: Filip Svoboda
 * 
 * Created on 16. prosinec 2014, 23:30
 */

#include "Faktura.h"

Faktura::Faktura(int cislo, float castka) {
    celkem = castka;
    pocetFaktur++;
    this->cislo = cislo;
}

Faktura::~Faktura() {
    pocetFaktur--;
}

float Faktura::getCelkem() {
    return celkem;
}

int Faktura::pocetFaktur = 0;

int Faktura::getPocetFaktur() {
    return pocetFaktur;
}

int Faktura::getCislo() {
    return cislo;
}