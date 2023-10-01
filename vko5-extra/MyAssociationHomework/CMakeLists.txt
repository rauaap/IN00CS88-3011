cmake_minimum_required(VERSION 3.5)

project(MyAssociationHomework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(MyAssociationHomework main.cpp
    controller.h controller.cpp
    view.h view.cpp
    button.h button.cpp)

target_compile_definitions(MyAssociationHomework PUBLIC DEBUG)

include(GNUInstallDirs)
install(TARGETS MyAssociationHomework
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
