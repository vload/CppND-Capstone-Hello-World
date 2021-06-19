#ifndef PHYSICS_H
#define PHYSICS_H

#include "PongData.h"
#include "constants.h"
#include <SDL2/SDL.h>

class Physics {
private:
    PongData& data;

    enum class Axis { X, Y };
    void mirror_ball_velocity(Axis axis);

public:
    Physics(PongData& data);

    void compute_physics();
};

#endif // PHYSICS_H