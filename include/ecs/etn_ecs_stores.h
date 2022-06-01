#ifndef INCLUDE_ECS_ETN_ECS_STORES
#define INCLUDE_ECS_ETN_ECS_STORES

#include "SDL2/SDL_types.h"

typedef struct
{
    /**
     * @brief the total count of components that are accessible
     * (calculated when init the ecs)
     *
     */
    Uint32 components_count;

    /**
     * @brief the max capacity that the store can handle
     *
     */
    Uint32 capacity;

    /**
     * @brief the total size calculated by the size of each component
     * total_size = size in bit of each components
     */
    size_t total_size;

    /**
     * @brief an array to store the size of each components
     *
     */
    size_t *data_size_array;

    /**
     * @brief an array to store offset of each components from the begining of the data
     *
     */
    size_t *data_offset_array;

    /**
     * @brief the raw data of the store
     * each entity have a contiguous band of memory with all the accessible component
     * size(data) = total size * max capacity
     *
     *  |entity_1||entity_2||entity_3||entity_4|
     * ----------------------------------------
     * |c1|c2|c3||c1|c2|c3||c1|c2|c3||c1|c2|c3|
     * ----------------------------------------
     *
     */
    void *data;
} ComponentStore;

typedef struct
{
    /**
     * @brief an array with the component mask(which components each entity has)
     *  |entity_1||entity_2||entity_3||entity_4|
     * ----------------------------------------
     * |ok|no|ok||ok|ok|ok||no|no|ok||ok|no|no|
     * ----------------------------------------
     * where ok=1 and no=0
     */
    Uint32 *mask_array;

    /**
     * @brief an array with the flag mask(which flags each entity has)
     * example:an entity could have the alive flag
     * additional infos for each entities
     */
    Uint32 *flag_array;

    /**
     * @brief the current count of created entities
     *
     */
    Uint32 entities_count;
    /**
     * @brief how many entities we can store
     *
     */
    Uint32 capacity;
} EntityStore;

#endif /* INCLUDE_ECS_ETN_ECS_STORES */
