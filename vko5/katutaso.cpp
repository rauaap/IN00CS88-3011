#include <iostream>
#include "katutaso.h"

Katutaso::Katutaso()
{
    std::cout << "katutaso constructor called" << std::endl;
}

Katutaso::~Katutaso() {
    std::cout << "katutaso destructor called" << std::endl;
}

void Katutaso::maaritaAsunnot() {
    as1 = std::make_unique<Asunto>();
    as2 = std::make_unique<Asunto>();
    std::cout << "Maaritetaan 2 asuntoa" << std::endl;
    as1->maarita(2, 60);
    as2->maarita(3, 100);
}

double Katutaso::laskeKulutus(double hinta) {
    return as1->laskeKulutus(hinta) +
           as2->laskeKulutus(hinta);
}
