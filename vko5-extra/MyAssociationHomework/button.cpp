#include <conio.h>
#include "button.h"

char Button::readKeyboard() {
    return getch();
}

#ifndef DEBUG
Button::~Button() {}
#else
#include <iostream>
Button::~Button() {std::cout << "button destr" << std::endl;}
#endif
