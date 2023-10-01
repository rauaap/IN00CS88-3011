cmake_minimum_required(VERSION 3.5)

project(vko5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(vko5 main.cpp
    kerros.h kerros.cpp
    katutaso.h katutaso.cpp
    kerrostalo.h kerrostalo.cpp
    asunto.h asunto.cpp


)

include(GNUInstallDirs)
install(TARGETS vko5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
