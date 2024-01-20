cmake_minimum_required(VERSION 3.27)
project(QtCalc VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(.)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QtCalc
        calculator.h
        calculator.cpp

        main.cpp
)

target_link_libraries(QtCalc
        Qt::Core
        Qt::Gui
        Qt::Widgets
)