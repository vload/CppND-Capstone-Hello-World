#include "Pong.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Pong().run();
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}