#include "Pong.h"

Pong::Pong() : data(), graphics(data), physics(data), input(data) {}

void Pong::run() {
    Uint32 frame_start = SDL_GetTicks();
    Uint32 frame_time;

    while(data.should_run) {
        graphics.render_one_frame();

        while(SDL_GetTicks() - frame_start < TARGET_FRAME_DURATION) {
            input.handle_input();
            physics.compute_physics();
            SDL_Delay(2);
        }

        frame_time = SDL_GetTicks() - frame_start;
        graphics.update_window_title(frame_time);

        frame_start = SDL_GetTicks();
    }
}