#include <stdint.h>
#include <SDL.h>
#include "renderloop/renderloop.hpp"

int main()
{
    RenderLoop renderloop;

    if (!renderloop.init())
        return 1;

    if (!renderloop.load())
        return 1;

    while (renderloop.loop())
    {
        // wait before processing next frame
        SDL_Delay(100);
    }

    renderloop.kill();

    return 0;
}