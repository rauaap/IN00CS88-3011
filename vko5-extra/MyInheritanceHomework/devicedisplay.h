#ifndef DEVICEDISPLAY_H
#define DEVICEDISPLAY_H

#include "devicebaseclass.h"

class DeviceDisplay : public DeviceBaseClass
{
public:
    DeviceDisplay();
    short getDisplayResolution();
    void setDisplayResolution();
private:
    short displayResolution;
};

#endif // DEVICEDISPLAY_H
