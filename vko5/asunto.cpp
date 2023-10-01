#include "asunto.h"
#include <iostream>

Asunto::Asunto()
{
    std::cout << "Asunto luotu" << std::endl;
}

Asunto::~Asunto() {
    std::cout << "Asunto tuhottu" << std::endl;
}

void Asunto::maarita(int _asukasMaara, int _neliot) {
    asukasMaara = _asukasMaara;
    neliot = _neliot;
    std::cout << "Asunto maaritetty. Asukkaita = " << asukasMaara
              << " Nelioita = " << neliot << std::endl;
}

double Asunto::laskeKulutus(double hinta) {
    return asukasMaara * neliot * hinta;
}
