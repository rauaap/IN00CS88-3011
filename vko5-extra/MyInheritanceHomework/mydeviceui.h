#ifndef MYDEVICEUI_H
#define MYDEVICEUI_H

#include <string>
#include "devicemouse.h"
#include "devicedisplay.h"
#include "devicetouchpad.h"

class MyDeviceUI
{
public:
    MyDeviceUI();
    ~MyDeviceUI();
    void uiShowMenu();
    void uiSetMouseInformation();
    void uiSetTouchPadInformation();
    void uiSetDisplayInformation();
    void uiShowDeviceInformation();
private:
    DeviceMouse* objectDeviceMouse;
    DeviceTouchPad* objectDeviceTouchPad;
    DeviceDisplay* objectDeviceDisplay;
};

#endif // MYDEVICEUI_H
