#include <iostream>
#include "kerrostalo.h"
using namespace std;

int main()
{
    Kerrostalo puistovahti;
    std::cout << "Kerrostalon kulutus = " <<
        puistovahti.laskeKulutus(1) << std::endl;
    return 0;
}
