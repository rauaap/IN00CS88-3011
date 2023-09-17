#include "italianchef.h"
#include <iostream>

using namespace std;

// Base class constructor already prints out the name
// and we do not have any initialization logic so this
// constructor body can be left empty
ItalianChef::ItalianChef(string name, int flourAmount, int waterAmount):
    Chef(name),
    flourAmount(flourAmount),
    waterAmount(waterAmount) {
}

string ItalianChef::getName() {
    return name;
}

void ItalianChef::makePasta(int additionalFlour, int additionalWater) {
    int totalFlour = flourAmount + additionalFlour;
    int totalWater = waterAmount + additionalWater;

    cout << "Chef " << name
         << " makes pasta with special recipe" << endl
         << "Chef " << name << " users jauhot = " << totalFlour << endl
         << "Chef " << name << " users vesi = " << totalWater << endl;
}
