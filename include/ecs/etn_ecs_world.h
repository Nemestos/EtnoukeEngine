#ifndef INCLUDE_ECS_ETN_ECS_WORLD
#define INCLUDE_ECS_ETN_ECS_WORLD

#include "ecs/etn_ecs_entity.h"

// forward declaration due to circular dependency;
struct Entity;

typedef struct
{

    Uint32 count;
    Uint32 cap;
    Entity *matched_entities;
} QueryResult;

typedef struct
{
    struct Entity **entities;
    int world_size;
    int entities_count;
} World;

typedef World *(*WorldInit)(World *);

World *world_default_init(World *world);
World *world_create(WorldInit worldInit, World *world);
int world_realloc_entities(World *world, int newSize);

#endif /* INCLUDE_ECS_ETN_ECS_WORLD */
