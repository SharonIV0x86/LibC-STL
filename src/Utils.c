#ifndef UTILS_C
#define UTILS_C
#include "../include/Utils.h"

int setContainerIteratorPropertiesAsPerType(DataType type, Iterator *itr, void *container)
{
    if (type == VECTOR_INT)
    {
        printf("\nIterator pointing to vector_int \n");
        itr->pointing_container_properties.size = ((Vector *)container)->size;
        itr->pointing_container_properties.capacity = ((Vector *)container)->capacity;
        // iterator->pointing_container_properties.size = ((Vector *)container)->size;
        // iterator->pointing_container_properties.capacity = ((Vector *)container)->capacity;
        return CONTAINER_ITERATOR_PROP_SUCC;
    }
    // adding more types checking as needed.
    return CONTAINER_ITERATOR_PROP_ERR;
}

#endif /*UTILS_C*/