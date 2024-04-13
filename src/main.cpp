#include <stdint.h>
#include <SDL.h>
#include "renderloop/renderloop.hpp"
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

namespace RenderVariables
{
    RenderLoop render = RenderLoop();
};

static void mainloop(void)
{
    RenderVariables::render.loop();

    if (RenderVariables::render.quit)
    {
#ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop(); /* this should "kill" the app. */
#endif
    }

    SDL_Delay(10);
}

int main()
{
    if (RenderVariables::render.init())
        return 1;

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(mainloop, 0, 1);
#else
    while (!RenderVariables::render.quit)
    {
        mainloop();
    }
#endif

    RenderVariables::render.kill();

    return 0;
}