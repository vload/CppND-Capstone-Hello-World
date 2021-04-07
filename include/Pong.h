#ifndef PONG_H
#define PONG_H

#include "Graphics.h"
#include "Input.h"
#include "Physics.h"
#include "PongData.h"

class Pong {
private:
    PongData data;

    Graphics graphics;
    Physics physics;
    Input input;

public:
    Pong();

    void run();
};

#endif // PONG_H