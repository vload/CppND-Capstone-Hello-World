#ifndef SDL_WRAPPERS_H
#define SDL_WRAPPERS_H

#include "constants.h"
#include <SDL2/SDL.h>
#include <exception>
#include <string>

class SDLException : public std::exception {
private:
    std::string text;
    virtual const char* what() const throw() { return text.c_str(); }

public:
    SDLException(std::string text_param) : std::exception() {
        text = text_param + "\n";
        text += "SDL_Error: " + std::string(SDL_GetError()) + "\n";
    }
};

class SDL {
public:
    SDL() {
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
            throw SDLException("SDL could not initialize.");
    }
    ~SDL() { SDL_Quit(); }
};

class Window {
private:
    SDL_Window* sdl_window;

public:
    Window() {
        sdl_window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

        if(sdl_window == nullptr)
            throw SDLException("Window could not be created.");
    }
    ~Window() { SDL_DestroyWindow(sdl_window); }

    SDL_Window* get() { return sdl_window; };
};

class Renderer {
private:
    SDL_Renderer* sdl_renderer;

public:
    Renderer(Window& window) {
        sdl_renderer = SDL_CreateRenderer(
            window.get(), -1, SDL_RENDERER_ACCELERATED);
        if(sdl_renderer == nullptr)
            throw SDLException("Renderer could not be created.");
    }

    SDL_Renderer* get() { return sdl_renderer; };
};

#endif // SDL_WRAPPERS_H