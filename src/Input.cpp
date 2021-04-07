#include "Input.h"

Input::Input(PongData& data) : data(data) {}

void Input::handle_input() {
    SDL_Event e;

    // User requests quit
    while(SDL_PollEvent(&e) != 0)
        if(e.type == SDL_QUIT)
            data.should_run = false;

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_W])
        data.bar_a.y -= MOVE_SPEED;
    if(currentKeyStates[SDL_SCANCODE_S])
        data.bar_a.y += MOVE_SPEED;

    if(currentKeyStates[SDL_SCANCODE_UP])
        data.bar_b.y -= MOVE_SPEED;
    if(currentKeyStates[SDL_SCANCODE_DOWN])
        data.bar_b.y += MOVE_SPEED;
}
