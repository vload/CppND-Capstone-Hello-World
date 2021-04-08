#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

constexpr int FPS{60};
constexpr int TARGET_FRAME_DURATION{1000 / FPS};
constexpr int SCREEN_WIDTH{1920};
constexpr int SCREEN_HEIGHT{1080};
constexpr int UNIT{16};
constexpr int BAR_HEIGHT{6};    // in units
constexpr int MOVE_SPEED{2};
constexpr int BALL_SPEED{1};
constexpr char NAME[] = "Pong";

constexpr SDL_Rect ball_reset{
    SCREEN_WIDTH / 2 - UNIT / 2,
    SCREEN_HEIGHT / 2 - UNIT / 2,
    UNIT,
    UNIT,
};
constexpr SDL_Rect top{
    -100,
    -100,
    SCREEN_WIDTH + 200,
    100,
};
constexpr SDL_Rect bottom{
    -100,
    SCREEN_HEIGHT,
    SCREEN_WIDTH + 200,
    100,
};
constexpr SDL_Rect a_wall{
    -100,
    -100,
    100,
    SCREEN_HEIGHT + 200,
};
constexpr SDL_Rect b_wall{
    SCREEN_WIDTH,
    -100,
    100,
    SCREEN_HEIGHT + 200,
};

constexpr SDL_Color BACKGROUND_COLOR{0x00, 0x00, 0x00, 0x00};
constexpr SDL_Color OBJECT_COLOR{0xFF, 0xFF, 0xFF, 0xFF};

#endif // CONSTANTS_H