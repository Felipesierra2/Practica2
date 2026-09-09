cmake_minimum_required(VERSION 3.16)

project(Practica2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practica2 main.cpp
    validaciones.h validaciones.cpp
    problemas.h problemas.cpp
    .gitignore
)

include(GNUInstallDirs)
install(TARGETS Practica2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
