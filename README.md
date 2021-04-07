# Pong Game

In this project i built a simple pong game.

The prject is divided into 4 main classes and a few helper classes.

## Rubric Criteria

All of the following are used throughout the project:

Classes use appropriate access specifiers for class members.

The project uses Object Oriented Programming techniques.

The project demonstrates an understanding of C++ functions and control structures.

The project makes use of references in function declarations.
* The input, physics and graphics classes have referances to the game data

The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
* The helper classes in SDL_Wrappers.h use RAII to create/destruct the SDL context.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.