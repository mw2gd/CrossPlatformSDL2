#include <iostream>
#include <SDL.h>
#include <SDL_video.h>
#include "renderloop.hpp"

bool Render::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 640, 320);
    SDL_RenderPresent(renderer);

    return true;
}

bool Render::init()
{
    // See last example for comments
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    uint32_t flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_SHOWN;
    SDL_CreateWindowAndRenderer(640, 320, 0, &window, &renderer);
    if (!window || !renderer)
    {
        std::cout << "Could not create window + renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Render::kill()
{
    // Tidy up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}