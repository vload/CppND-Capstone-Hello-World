#include "Graphics.h"

Graphics::Graphics(PongData& data)
    : sdl(SDL()), window(Window()), renderer(Renderer(window)),
      data(data) {}

void Graphics::clear_screen() {
    SDL_SetRenderDrawColor(renderer.get(), BACKGROUND_COLOR.r,
        BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
    SDL_RenderClear(renderer.get());
}

void Graphics::render_one_frame() {
    clear_screen();

    // Draw Bars and Ball
    SDL_SetRenderDrawColor(renderer.get(), OBJECT_COLOR.r,
        OBJECT_COLOR.g, OBJECT_COLOR.b, OBJECT_COLOR.a);
    SDL_RenderFillRect(renderer.get(), &data.bar_a);
    SDL_RenderFillRect(renderer.get(), &data.bar_b);
    SDL_RenderFillRect(renderer.get(), &data.ball);

    // Update Screen
    SDL_RenderPresent(renderer.get());
}

void Graphics::update_window_title(Uint32 frame_time) {
    timer += frame_time;
    frames++;

    if(timer > 1000) {
        timer = 0;
        std::string title{"Pong score " +
                          std::to_string(data.score_a) + ":" +
                          std::to_string(data.score_b) +
                          " FPS: " + std::to_string(frames)};
        SDL_SetWindowTitle(window.get(), title.c_str());

        frames = 0;
    }
}