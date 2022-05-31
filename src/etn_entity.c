/*
** ETNA PROJECT, 31/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      source code for game entities
*/
#include "etn.h"

Entity *entity_default_init(Entity *entity, char *name)
{
    static EntityId id;
    if (name == NULL)
    {
        entity->name = ETN_ENTITY_DEFAULT;
    }
    else
    {
        entity->name = strdup(name);
    }
    entity->id = ++id;
    SDL_Log("Init %s with id %u", entity->name, entity->id);

    return entity;
}
