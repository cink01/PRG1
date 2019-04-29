#include "fodeslana.h"

FakturaVydana::FakturaVydana(int cislo, float castka) : Faktura(cislo, castka) {
}

void FakturaVydana::zauctuj(Ucet &ucet) {
	ucet.vybrat(getCelkem());
}