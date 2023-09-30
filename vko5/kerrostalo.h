#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "katutaso.h"

class Kerrostalo
{
public:
    Kerrostalo();
    double laskeKulutus(double);
private:
    std::unique_ptr<Katutaso> eka;
    std::unique_ptr<Kerros> toka;
    std::unique_ptr<Kerros> kolmas;
};

#endif // KERROSTALO_H
