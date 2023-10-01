#include <iostream>
#include "view.h"

void View::printCharacter(char parameterCharacter) {
    std::cout << parameterCharacter << std::endl;
}

#ifndef DEBUG
View::~View() {}
#else
View::~View() {std::cout << "view destr" << std::endl;}
#endif
