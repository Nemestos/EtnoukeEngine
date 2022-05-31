#ifndef INCLUDE_ETN_ENTITY
#define INCLUDE_ETN_ENTITY

#include "etn_world.h"
#include "string.h"

typedef Uint32 EntityId;

typedef struct
{
    EntityId id;
    char *name;
} Entity;

typedef Entity *(*EntityInit)(Entity *);

Entity *entity_default_init(Entity *entity);
Entity *entity_create(char *name, World *world, EntityInit entityInit);
void entity_set_name(Entity *entity, char *name);

#endif /* INCLUDE_ETN_ENTITY */
