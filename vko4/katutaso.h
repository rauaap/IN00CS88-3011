#ifndef KATUTASO_H
#define KATUTASO_H
#include <memory>
#include "kerros.h"

class Katutaso : public Kerros
{
public:
    Katutaso();
    ~Katutaso();
    void maaritaAsunnot();
    double laskeKulutus(double);

    // As with base class "Kerros"
    // the "maarita" member function takes
    // care of actually constructing these
    // "Asunto" members.
    std::unique_ptr<Asunto> as1;
    std::unique_ptr<Asunto> as2;
};

#endif // KATUTASO_H
