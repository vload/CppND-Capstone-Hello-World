#ifndef PONGDATA_H
#define PONGDATA_H

#include "constants.h"
#include <SDL2/SDL.h>

struct PongData {
    int score_a{0};
    int score_b{0};

    SDL_Rect ball{
        SCREEN_WIDTH / 2 - UNIT / 2,
        SCREEN_HEIGHT / 2 - UNIT / 2,
        UNIT,
        UNIT,
    };
    SDL_Rect bar_a{
        UNIT,
        SCREEN_HEIGHT / 2 - BAR_HEIGHT / 2 * UNIT,
        UNIT,
        BAR_HEIGHT* UNIT,
    };
    SDL_Rect bar_b{
        SCREEN_WIDTH - 2 * UNIT,
        SCREEN_HEIGHT / 2 - BAR_HEIGHT / 2 * UNIT,
        UNIT,
        BAR_HEIGHT* UNIT,
    };

    float ball_v_x{BALL_SPEED};
    float ball_v_y{BALL_SPEED};

    bool should_run{true};
};

#endif // PONGDATA_H