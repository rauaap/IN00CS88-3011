#include <iostream>
#include "kerrostalo.h"
using namespace std;

int main()
{
    auto puistovahti = std::make_unique<Kerrostalo>();
    std::cout << "Kerrostalon kulutus = " <<
        puistovahti->laskeKulutus(1) << std::endl;
    return 0;
}
