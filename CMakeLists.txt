cmake_minimum_required(VERSION 3.21)
project(gcalc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(gcalc main.cpp MainWindow.cpp MainWindow.h MainWindow.ui SimpleCalculatorStatus.cpp SimpleCalculatorStatus.h)
target_link_libraries(gcalc
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

