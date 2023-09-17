#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(string name) : name(name)
{
    cout << "Chef " << name << " konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << name << " destruktori" << endl;
}

void Chef::makeSalad() {
    cout << "Chef " << name << " makes salad" << endl;;
}

void Chef::makeSoup() {
    cout << "Chef " << name << " makes soup" << endl;;
}
