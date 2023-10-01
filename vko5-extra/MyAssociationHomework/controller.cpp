#include <conio.h>
#include <memory>
#include "controller.h"

using std::unique_ptr;

Controller::Controller(
    const unique_ptr<Button> &parameterButton,
    const unique_ptr<View> &parameterView
):
    objectButton(parameterButton),
    objectView(parameterView)
{
    listenMessage();
}

void Controller::listenMessage() {
    while (!kbhit());
    char pressedKey = objectButton->readKeyboard();
    objectView->printCharacter(pressedKey);
}

#ifndef DEBUG
Controller::~Controller() {}
#else
#include <iostream>
Controller::~Controller() {std::cout << "controller destr" << std::endl;}
#endif
