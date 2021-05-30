cmake_minimum_required(VERSION 3.17)
project(TAProject2021_MenuaHovhannisyan)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TAProject2021_MenuaHovhannisyan main.cpp TA_MenuaHovhannisyan/DFA.h TA_MenuaHovhannisyan/State.cpp TA_MenuaHovhannisyan/State.h TA_MenuaHovhannisyan/DFA.cpp TA_MenuaHovhannisyan/Transition.cpp TA_MenuaHovhannisyan/Transition.h TA_MenuaHovhannisyan/NFA.cpp TA_MenuaHovhannisyan/NFA.h shop.cpp shop.h car.cpp car.h system.cpp system.h TA_MenuaHovhannisyan/RE.cpp TA_MenuaHovhannisyan/RE.h TA_MenuaHovhannisyan/Node.cpp TA_MenuaHovhannisyan/Node.h TA_MenuaHovhannisyan/Edge.cpp TA_MenuaHovhannisyan/Edge.h Interface/main.ccp Interface/mainwindow.cpp Interface/mainwindow.h)

target_link_libraries(TAProject2021_MenuaHovhannisyan Qt5::Widgets)