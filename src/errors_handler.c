#include "engine.h"

int check_return_int(int return_value, char *good_message)
{
    if (return_value != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
        return 1;
    }
    if (good_message != NULL)
    {
        SDL_Log("%s", good_message);
    }
    return 0;
}

int check_return_ptr(void *ptr, char *good_message)
{
    if (ptr == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
        return 1;
    }
    if (good_message != NULL)
    {
        SDL_Log("%s", good_message);
    }
    return 0;
}
