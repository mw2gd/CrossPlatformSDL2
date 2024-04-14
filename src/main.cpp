#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "renderloop.hpp"

namespace GlobalVariables
{
    Render render = Render();
};

void mainloop(void)
{
    if (!GlobalVariables::render.render())
    {
        std::cout << "Error rendering: " << std::endl;
    }

#ifdef EMSCRIPTEN
    if (GlobalVariables::render.quit)
    {
        emscripten_cancel_main_loop();
    }
#endif
}

int main(int argc, char *argv[])
{
    GlobalVariables::render.init();

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(mainloop, 60, 1);
#else
    while (GlobalVariables::render.quit)
    {
        mainloop();
    }
#endif

    GlobalVariables::render.kill();

    return 0;
}