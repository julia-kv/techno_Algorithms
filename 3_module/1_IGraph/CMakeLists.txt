cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(untitled main.cpp
        src/ListGraph.cpp
        src/MatrixGraph.cpp
        src/SetGraph.cpp
        src/ArcGraph.cpp)

