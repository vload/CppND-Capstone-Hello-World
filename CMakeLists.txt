cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS}")

project(Pong)
find_package(SDL2)

add_executable(PongGame src/main.cpp src/Pong.cpp src/Input.cpp src/Physics.cpp src/Graphics.cpp)
target_link_libraries(PongGame SDL2::SDL2)
target_include_directories(PongGame PUBLIC include)
