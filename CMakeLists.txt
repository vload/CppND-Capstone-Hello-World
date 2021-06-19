cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++20 -fmodules-ts)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Snake)

file(GLOB_RECURSE SnakeGame_SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(SnakeGame ${SnakeGame_SRC})
target_include_directories(SnakeGame PUBLIC include)

# Load SDL2
find_program(LSB_RELEASE_EXEC lsb_release)
execute_process(COMMAND ${LSB_RELEASE_EXEC} -is OUTPUT_VARIABLE LSB_RELEASE_ID_SHORT OUTPUT_STRIP_TRAILING_WHITESPACE)
message("Your distro is ${LSB_RELEASE_ID_SHORT}")
find_package(SDL2 REQUIRED)
if ("${LSB_RELEASE_ID_SHORT}" STREQUAL "Arch")
    message("Arch distro detected, using Arch CMake linkage")
    target_link_libraries(SnakeGame SDL2::SDL2)
else ()
    message("Non-Arch distro detected, using normal linkage")
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES) # Fix because CMake is stupid, remove trailing spaces
    include_directories(SnakeGame ${SDL2_INCLUDE_DIRS})
    target_link_libraries(SnakeGame ${SDL2_LIBRARIES})
endif ()
                                        