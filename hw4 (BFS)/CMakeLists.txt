cmake_minimum_required(VERSION 3.29)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5 main.cpp
        PandemicSimulator.h
        PandemicSimulator.cpp
        City.h
        City.cpp
        Node.cpp
        ListInterface.h
        LinkedList.cpp
        QueueInterface.h
        ListQueue.cpp
)
