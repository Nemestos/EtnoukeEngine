#ifndef INCLUDE_ETN_ENTITY
#define INCLUDE_ETN_ENTITY

#include "string.h"
#include "etn_world.h"
#include "etn_utils.h"
#include "etn_consts.h"
#include "SDL2/SDL.h"

typedef Uint32 EntityId;

typedef struct
{
    EntityId id;
    char *name;
} Entity;

typedef Entity *(*EntityInit)(Entity *);

Entity *entity_default_init(Entity *entity, char *name);
Entity *entity_create(char *name, World *world, EntityInit entityInit);
void entity_free(Entity *entity, World *world);
void entity_set_name(Entity *entity, char *name);

#endif /* INCLUDE_ETN_ENTITY */
