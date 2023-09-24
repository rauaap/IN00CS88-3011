#ifndef KERROS_H
#define KERROS_H
#include <memory>
#include "asunto.h"

class Kerros
{
public:
    Kerros();
    virtual ~Kerros();
    virtual void maaritaAsunnot();
    virtual double laskeKulutus(double);

    // Initialize floor apartments as null
    // unique pointers and let the "maarita"
    // member function take care of constructing them.
    // This way the derived floor class doesn't create
    // these apartments when this base class constructor
    // is called by the derived class.
    std::unique_ptr<Asunto> as1;
    std::unique_ptr<Asunto> as2;
    std::unique_ptr<Asunto> as3;
    std::unique_ptr<Asunto> as4;
};

#endif // KERROS_H
