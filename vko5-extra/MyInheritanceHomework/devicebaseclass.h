#ifndef DEVICEBASECLASS_H
#define DEVICEBASECLASS_H
#include <iostream>

class DeviceBaseClass
{
public:
    DeviceBaseClass();
    void setDeviceID();
    short getDeviceID();
private:
    short deviceID;
};

#endif // DEVICEBASECLASS_H
