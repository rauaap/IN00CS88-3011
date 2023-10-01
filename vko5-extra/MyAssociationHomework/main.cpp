#include <memory>
#include "controller.h"
#include "view.h"
#include "button.h"

using std::make_unique;

int main() {
    auto objectButton = make_unique<Button>();
    auto objectView = make_unique<View>();

    auto objectController = make_unique<Controller>(
        objectButton,
        objectView
    );

    return 0;
}
