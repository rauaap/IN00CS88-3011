#include "devicedisplay.h"

DeviceDisplay::DeviceDisplay()
{

}

short DeviceDisplay::getDisplayResolution() {
    return displayResolution;
}

void DeviceDisplay::setDisplayResolution() {
    std::cin >> displayResolution;
}
