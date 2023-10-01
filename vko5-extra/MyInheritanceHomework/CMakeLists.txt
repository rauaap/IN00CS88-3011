cmake_minimum_required(VERSION 3.5)

project(MyInheritanceHomework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(MyInheritanceHomework main.cpp
    devicebaseclass.h devicebaseclass.cpp
    devicemouse.h devicemouse.cpp
    devicetouchpad.h devicetouchpad.cpp
    devicedisplay.h devicedisplay.cpp
    mydeviceui.h mydeviceui.cpp
)

include(GNUInstallDirs)
install(TARGETS MyInheritanceHomework
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
