/* 
 * File:   Ucet.cpp
 * Author: Filip
 * 
 * Created on 30. listopad 2014, 17:28
 */

#include "Ucet.h"
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


Ucet::Ucet(): MAX_VYBER(5000), MAX_VKLAD(100000) {
    zustatek = prichoziPlatby = odchoziPlatby = usepsneVybery = uspesneVklady = 0;
}

Ucet::Ucet(string jmeno, string prijmeni, string cu) : MAX_VYBER(5000), MAX_VKLAD(100000) {
    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    this->cu = cu;
    zustatek = prichoziPlatby = odchoziPlatby = usepsneVybery = uspesneVklady = 0;
}

// Pro zapis do souboru
ostream& operator <<(ostream& os, Ucet &u) {
        os << u.cu << endl << u.jmeno << " " << u.prijmeni << endl << roundf(u.zustatek *100)/100 << endl << u.uspesneVklady << endl << u.usepsneVybery << endl << roundf(u.prichoziPlatby *100)/100 << endl << roundf(u.odchoziPlatby *100)/100;
        return os;
    }

// Pro nacteni dat ze souboru
istream& operator >>(istream& is, Ucet &u)
{ 
    is >> u.cu >> u.jmeno >> u.prijmeni >> u.zustatek >> u.uspesneVklady >> u.usepsneVybery >> u.prichoziPlatby >> u.odchoziPlatby;
        return is;
}

string Ucet::getStavString() {
    ostringstream buffer;
    buffer << "zustatek: " << zustatek << "\nsoucet prichozich plateb: " << prichoziPlatby << "\nsoucet odchozich plateb: " << odchoziPlatby << "\npocet vkladu: " << uspesneVklady << "\npocet vyberu: " << usepsneVybery;
    return buffer.str();
}

string Ucet::getInfoString() {
    ostringstream buffer;
    buffer << "cislo uctu: " << cu << "\nmajitel: " << jmeno << " " << prijmeni << "\npocet vkladu: " << uspesneVklady << "\npocet vyberu: " << usepsneVybery << "\nsoucet prichozich plateb: " << prichoziPlatby << "\nsoucet odchozich plateb: " << odchoziPlatby;
    return buffer.str();
    }

void Ucet::vlozit(float castka) {
    if (castka > MAX_VKLAD)
        throw "Zadana castka prekracuje limit pro maximlani povoleny vklad.";
    if (castka < 0)
        throw "Prosim kladna cisla.";
    zustatek += castka;
    uspesneVklady++;
    prichoziPlatby += castka;
}

void Ucet::vybrat(float castka) {
    if (castka > MAX_VYBER || castka > zustatek || castka < 0)
        throw "Nelze vybrat zadanou castku";
    zustatek -= castka;
    usepsneVybery++;
    odchoziPlatby += castka;
}