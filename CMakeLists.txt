cmake_minimum_required(VERSION 3.12)
project(312lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(312lab5
        song.cpp
        song.h
        UtPod.cpp
        UtPod.h
        UtPodDriver.cpp)
