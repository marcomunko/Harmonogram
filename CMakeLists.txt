cmake_minimum_required(VERSION 3.26)
project(Harmonogram)

set(CMAKE_CXX_STANDARD 23)

add_executable(Harmonogram main.cpp
        Czas.cpp
        Czas.h
        Harmonogram.cpp
        Harmonogram.h)
