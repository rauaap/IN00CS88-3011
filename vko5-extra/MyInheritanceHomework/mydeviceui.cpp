#ifdef _WIN32
#define CLEAR "cls"
#elif __linux__
#define CLEAR "clear"
#else
#define CLEAR ""
#endif

#include <limits>
#include <functional>
#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI():
    objectDeviceMouse(new DeviceMouse),
    objectDeviceTouchPad(new DeviceTouchPad),
    objectDeviceDisplay(new DeviceDisplay) {
}

MyDeviceUI::~MyDeviceUI() {
    delete objectDeviceMouse;
    delete objectDeviceTouchPad;
    delete objectDeviceDisplay;
}

void MyDeviceUI::uiShowMenu() {
    std::system(CLEAR);

    std::cout << "DEVICE MENU" << std::endl
              << "===========" << std::endl
              << "1: Set Mouse Information" << std::endl
              << "2: Set Touch Pad Information" << std::endl
              << "3: Set Display Information" << std::endl
              << "4: Show Devices Information" << std::endl
              << "5: Finish" << std::endl << std::endl
              << "Choose: ";

    short choice;
    std::cin >> choice;
    std::system(CLEAR);

    if (choice == 5) return;

    switch (choice) {
    case 1:
        uiSetMouseInformation();
        break;
    case 2:
        uiSetTouchPadInformation();
        break;
    case 3:
        uiSetDisplayInformation();
        break;
    case 4:
        uiShowDeviceInformation();
        break;
    default:
        break;
    }

    uiShowMenu();
}

template <class Device>
static void setDeviceInformationHelper(
    std::string device,
    std::string setting,
    Device* devicePointer,
    void (Device::*setter)()
) {
    std::cout << "SET " << device << " INFORMATION" << std::endl
          << "========================" << std::endl
          << "Set " << device << " Device ID: ";

    devicePointer->setDeviceID();

    std::cout << "Set " << setting << ": ";
    (devicePointer->*setter)();
}

void MyDeviceUI::uiSetMouseInformation() {
    setDeviceInformationHelper(
        "Mouse",
        "Mouse Primary Button",
        objectDeviceMouse,
        &DeviceMouse::setPrimaryButton
    );
}

void MyDeviceUI::uiSetTouchPadInformation() {
    setDeviceInformationHelper(
        "Touch Pad",
        "Touch Pad sensitivity",
        objectDeviceTouchPad,
        &DeviceTouchPad::setTouchPadSensitivity
    );
}

void MyDeviceUI::uiSetDisplayInformation() {
    setDeviceInformationHelper(
        "Display",
        "Display resolution",
        objectDeviceDisplay,
        &DeviceDisplay::setDisplayResolution
    );
}

template <class Device>
static void showDeviceInfoHelper(
    std::string device,
    std::string setting,
    Device* obj,
    short (Device::*getter)()
) {
    std::cout << device << " information:" << std::endl
              << "\tID: " << obj->getDeviceID() << std::endl
              << "\t" << setting << ": " << (obj->*getter)() << std::endl;
}

void MyDeviceUI::uiShowDeviceInformation() {
    showDeviceInfoHelper<DeviceMouse>(
        "Mouse",
        "Primary button",
        objectDeviceMouse,
        &DeviceMouse::getPrimaryButton
    );

    showDeviceInfoHelper<DeviceTouchPad>(
        "Touch Pad",
        "Sensitivity",
        objectDeviceTouchPad,
        &DeviceTouchPad::getTouchPadSensitivity
    );

    showDeviceInfoHelper<DeviceDisplay>(
        "Display",
        "Resolution",
        objectDeviceDisplay,
        &DeviceDisplay::getDisplayResolution
    );

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
