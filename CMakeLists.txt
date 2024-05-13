cmake_minimum_required(VERSION 3.28)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graphs main.cpp
        Graph.h
        Graph.cpp
        Action.h
        Action.cpp
        Print.h
        Print.cpp
        Traverser.h
        Traverser.cpp
        Sorter.h
        Sorter.cpp
        InvalidDataException.h
        InvalidDataException.cpp
        KahnSort.h
        KahnSort.cpp
        TarjanSort.h
        TarjanSort.cpp)
