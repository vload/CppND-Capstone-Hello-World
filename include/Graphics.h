#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "PongData.h"
#include "SDL_Wrappers.h"

class Graphics {
    SDL sdl;
    Window window;
    Renderer renderer;
    PongData& data;

    Uint32 timer{0};
    int frames{0};

    void clear_screen();

public:
    Graphics(PongData& data);

    void render_one_frame();

    void update_window_title(Uint32 frame_time);
};

#endif // GRAPHICS_H