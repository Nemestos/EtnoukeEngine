#include "engine/errors_handler.h"

int check_return(void *return_value, char *good_message)
{
    if (return_value == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
        return 1;
    }
    if (good_message != NULL)
    {
        SDL_Log(good_message);
        return 0;
    }
}
