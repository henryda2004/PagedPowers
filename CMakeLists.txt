cmake_minimum_required(VERSION 3.24)
project(PagedPowers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)
find_package(Qt5 COMPONENTS Xml REQUIRED)
add_executable(PagedPowers main.cpp Power.cpp Power.h Strategy.cpp Strategy.h)
target_link_libraries(PagedPowers
        Qt5::Core
        Qt5::Xml
        )

