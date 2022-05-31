#ifndef INCLUDE_ETN_WORLD
#define INCLUDE_ETN_WORLD

#include "etn_entity.h"

// forward declaration due to circular dependency;
struct Entity;
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

#endif /* INCLUDE_ETN_WORLD */
