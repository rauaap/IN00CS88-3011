#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass()
{

}

short DeviceBaseClass::getDeviceID() {
    return deviceID;
}

void DeviceBaseClass::setDeviceID() {
    std::cin >> deviceID;
}

