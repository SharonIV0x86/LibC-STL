#define CONTAINER_ITERATOR_PROP_SUCC 1
#define CONTAINER_ITERATOR_PROP_ERR 0

typedef enum
{
    STR,
    INT,
    FLOAT,
    CHAR,
    DOUBLE
} DataType;
typedef enum
{
    VECTOR_STR,
    VECTOR_INT,
    VECTOR_FLOAT,
    VECTOR_CHAR,
    VECTOR_DOUBLE
} VectorContainerType;
typedef struct vector
{
    void **data;
    size_t capacity;
    size_t size;
    DataType type;

} Vector;
typedef struct containerProperties
{
    size_t size;
    size_t capacity;
    VectorContainerType cntType;

} conProp;
typedef struct iterator
{
    size_t index;
    DataType type;
    void *container;
    void *data;
    size_t container_size;
    conProp pointing_container_properties;

} Iterator;

void getNormalType(DataType type, DataType *actualType);
void getVectorType(Vector *vec, DataType type, DataType *actualType);
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
    return CONTAINER_ITERATOR_PROP_ERR;
}