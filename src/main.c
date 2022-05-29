#include "engine.h"
#include "stdbool.h"
int main()
{
    check_return_int(SDL_Init(SDL_INIT_VIDEO), "Video init : success");
    StateManager *sm = sm_init();
    Graphics *graphics = graphics_init();
    if (graphics == NULL)
    {
        sm_free(sm);
        SDL_Quit();
        return 1;
    }

    bool playing = true;
    SDL_Event e;

    while (playing)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                playing = false;
        }
    }
    graphics_free(graphics);
    sm_free(sm);

    return 0;
}
