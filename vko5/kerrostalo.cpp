#include "kerrostalo.h"

Kerrostalo::Kerrostalo():
    eka(std::make_unique<Katutaso>()),
    toka(std::make_unique<Kerros>()),
    kolmas(std::make_unique<Kerros>())
{
    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
}

double Kerrostalo::laskeKulutus(double hinta) {
    return eka->laskeKulutus(hinta) +
           toka->laskeKulutus(hinta) +
           kolmas->laskeKulutus(hinta);
}
