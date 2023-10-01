#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad()
{

}

short DeviceTouchPad::getTouchPadSensitivity() {
    return touchPadSensitivity;
}

void DeviceTouchPad::setTouchPadSensitivity() {
    std::cin >> touchPadSensitivity;
}
