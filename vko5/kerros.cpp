#include "kerros.h"
#include "katutaso.h"
#include <iostream>

Kerros::Kerros()
{
    std::cout << "kerros constructor called" << std::endl;
}

Kerros::~Kerros() {
    std::cout << "kerros destructor called" << std::endl;
}

void Kerros::maaritaAsunnot() {
    as1 = std::make_unique<Asunto>();
    as2 = std::make_unique<Asunto>();
    as3 = std::make_unique<Asunto>();
    as4 = std::make_unique<Asunto>();
    std::cout << "Maaritetaan 4 asuntoa" << std::endl;
    as1->maarita(1, 30);
    as2->maarita(1, 30);
    as3->maarita(1, 40);
    as4->maarita(2, 60);
}

double Kerros::laskeKulutus(double hinta) {
    return as1->laskeKulutus(hinta) +
           as2->laskeKulutus(hinta) +
           as3->laskeKulutus(hinta) +
           as4->laskeKulutus(hinta);
}
