#include "devicemouse.h"

DeviceMouse::DeviceMouse() {

}

short DeviceMouse::getPrimaryButton() {
    return primaryButton;
}

void DeviceMouse::setPrimaryButton() {
    std::cin >> primaryButton;
}
