#include <stdint.h>
#include <SDL.h>
#include <SDL_video.h>

class RenderLoop
{
public:
    bool init();
    void kill();
    bool load();
    bool loop();
    bool render();

private:
    // Pointers to our window and surfaces
    SDL_Window *window;
    SDL_Renderer *renderer;
};