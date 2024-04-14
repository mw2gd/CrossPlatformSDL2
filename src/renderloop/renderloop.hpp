#include <stdint.h>
#include <SDL.h>
#include <SDL_video.h>

#pragma once

class Render
{
public:
    bool init();
    void kill();
    void loop();
    bool render();

    bool quit = false;

private:
    // Pointers to our window and surfaces
    SDL_Window *window;
    SDL_Renderer *renderer;
};