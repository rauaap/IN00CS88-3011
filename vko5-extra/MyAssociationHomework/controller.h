#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>

#include "button.h"
#include "view.h"

using std::unique_ptr;

class Controller
{
public:
    ~Controller();
    Controller(
        const unique_ptr<Button> &parameterButton,
        const unique_ptr<View> &parameterView
    );

    void listenMessage();
private:
    const unique_ptr<View> &objectView;
    const unique_ptr<Button> &objectButton;
};

#endif // CONTROLLER_H
