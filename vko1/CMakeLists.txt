cmake_minimum_required(VERSION 3.5)

project(IN00CS88-3011-Vko1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(IN00CS88-3011-Vko1 main.cpp)

include(GNUInstallDirs)
install(TARGETS IN00CS88-3011-Vko1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
