#include "etn_engine.h"
#include "stdbool.h"
int main()
{
    EngineOptions options = {"Fruitz game for charo by charo", 1280, 720};
    Engine *engine = engine_create(&options, &engine_default_init);

    SDL_Event e;

    while (engine->running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                engine->running = false;
        }
    }

    engine_free(engine);

    return 0;
}
