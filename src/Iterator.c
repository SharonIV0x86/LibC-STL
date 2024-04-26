
#include "../include/Iterator.h"
#include "../include/Vector.h"
Iterator *create_iterator(VectorContainerType type, void *container)
{
    Iterator *iterator = (Iterator *)malloc(sizeof(Iterator));
    iterator->type = type;
    iterator->index = 0;
    iterator->container = container;

    setContainerIteratorPropertiesAsPerType(type, iterator, container);
        
    if (container != NULL)
    {
        if (iterator != NULL)
        {
            iterator->data = vector_at(container, 0);
        }
        return iterator;
    }
    return iterator;
}
void Advance(Iterator *itr)
{
    if (itr != NULL && itr->data != NULL)
    {
        if (itr->index == itr->pointing_container_properties.size)
        {
            printf("\n\n Invalid advance arg. Container going OOB \n\n");
            exit(EXIT_FAILURE);
        }
        itr->data = vector_at(itr->container, itr->index + 1);
        itr->index++;
    }
}
void Advance_by(Iterator *itr, size_t step)
{
    if (itr != NULL && itr->data != NULL && step >= 0)
    {
        if (itr->index + step > itr->pointing_container_properties.size)
        {
            printf("\nInvalid advance_by arg. Container going OOB \n\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            itr->data = vector_at(itr->container, itr->index + step);
            itr->index += step;
        }
    }
}
Iterator *Begin(void *container)
{
    Iterator *itr = (Iterator *)malloc(sizeof(Iterator));

    itr->container = container;
    itr->index = 0;
    itr->data = vector_at(container, 0);
    // printf("Container type: %d", itr->pointing_container_properties.cntType); DEBUG
    // take inspiration for vector_at function from here!
    return itr;
}