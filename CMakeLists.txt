cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Pong)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(PongGame src/main.cpp src/Pong.cpp src/Input.cpp src/Graphics.cpp src/Physics.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

target_link_libraries(PongGame ${SDL2_LIBRARIES})                                              