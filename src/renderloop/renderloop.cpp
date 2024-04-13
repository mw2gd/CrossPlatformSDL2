#include <iostream>
#include <SDL.h>
#include <SDL_video.h>
#include "renderloop.hpp"

void RenderLoop::loop()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
        case SDL_QUIT:
            quit = true;
        case SDL_KEYDOWN:
            break;
        case SDL_KEYUP:
            // can also test individual keys, modifier flags, etc, etc.
            break;
        case SDL_MOUSEMOTION:
            // etc.
            break;
        }
    }

    if (!render())
    {
        std::cout << "Error rendering: " << std::endl;
    }
}

bool RenderLoop::render()
{
    // Randomly change the colour
    Uint8 red = rand() % 255;
    Uint8 green = rand() % 255;
    Uint8 blue = rand() % 255;

    // Fill the screen with the colour
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return true;
}

bool RenderLoop::init()
{
    // See last example for comments
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    uint32_t flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, flags);
    if (!window)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return -1;
    }

    return true;
}

bool RenderLoop::load()
{
    return true;
}

void RenderLoop::kill()
{
    // Tidy up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}