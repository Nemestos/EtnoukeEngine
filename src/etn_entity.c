/*
** ETNA PROJECT, 31/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      source code for game entities
*/
#include "etn_entity.h"

Entity *entity_default_init(Entity *entity, char *name)
{
    static EntityId id;
    if (name == NULL)
    {
        entity->name = strdup(ETN_ENTITY_DEFAULT);
    }
    else
    {
        entity->name = strdup(name);
    }
    entity->id = ++id;
    SDL_Log("Init %s with id %u", entity->name, entity->id);

    return entity;
}
Entity *entity_create(char *name, World *world, EntityInit entityInit)
{
    Entity *entity = malloc(sizeof(Entity));
    MALLER(entity, error, "Cant alloc entity: %s", name);

error:
    entity_free(entity, world);
}

void entity_set_name(Entity *entity, char *name)
{
    entity->name = realloc(entity->name, sizeof(char) * strlen(name));
    strcpy(name, entity->name);
}

void entity_free(Entity *entity, World *world)
{
    free(entity->name);
    free(entity);
}
