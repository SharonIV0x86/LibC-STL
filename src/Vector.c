#include "../include/Vector.h"

struct vector
{
    void **data;
    size_t capacity;
    size_t size;
    DataType type;
};
Vector *create_Vector(size_t capacity, DataType type)
{

    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (vec == NULL)
    {
        return NULL;
    }
    vec->type = type;
    vec->data = (void **)calloc(capacity, sizeof(void *));
    if (vec->data == NULL)
    {
        free(vec);
        return NULL;
    }
    vec->capacity = capacity;
    vec->size = 0;
    return vec;
}

void delete_vector(Vector *vec)
{
    if (vec == NULL)
    {
        return;
    }

    // Free memory for each element in the vector
    for (size_t i = 0; i < vec->size; ++i)
    {
        free(vec->data[i]);
    }
    free(vec->data);
    free(vec);
}

int resize_vector(Vector *vec, size_t size)
{
    void **new_data = (void **)realloc(vec->data, size * sizeof(void *));
    if (new_data == NULL)
    {
        return 0;
    }
    vec->data = new_data;
    vec->capacity = size;
    if (vec->size > size)
    {
        vec->size = size;
    }
    return 1;
}
int pb_int(Vector *vec, int value)
{
    if (vec->type != INT)
    {
        return 0; // Wrong type
    }
    if (vec->size >= vec->capacity)
    {
        size_t new_capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if (!resize_vector(vec, new_capacity))
        {
            return 0;
        }
    }
    vec->data[vec->size] = malloc(sizeof(int));
    if (vec->data[vec->size] == NULL)
    {
        return 0;
    }
    *(int *)(vec->data[vec->size]) = value;
    ++vec->size;
    return 1;
}
int pb_float(Vector *vec, float value)
{
    if (vec->type != FLOAT)
    {
        printf("Expected type to be FLOAT\n");
        return 0; // Wrong type
    }

    if (vec->size >= vec->capacity)
    {
        size_t new_capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if (!resize_vector(vec, new_capacity))
        {
            return 0;
        }
    }
    vec->data[vec->size] = malloc(sizeof(float));
    if (vec->data[vec->size] == NULL)
        return 0;

    *(float *)(vec->data[vec->size]) = value;
    ++vec->size;
    return 1;
}
int pb_char(Vector *vec, char ch)
{
    printf("Pushing to char vector probably success! \n");

    if (vec->type != CHAR)
    {
        printf("Expected type to be CHAR\n");
        return 0; // Wrong type
    }
    if (vec->size >= vec->capacity)
    {
        size_t __new_capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if (!resize_vector(vec, __new_capacity))
        {
            return 0;
        }
    }
    vec->data[vec->size] = malloc(sizeof(char));
    if (vec->data[vec->size] == NULL)
        return 0;

    *(char *)(vec->data[vec->size]) = ch;
    ++vec->size;
    printf("Pushing to char vector probably success! \n");
    return 1;
}
int pb_double(Vector *vec, double value)
{
    if (vec->type != DOUBLE)
    {
        printf("\n Expected type to be DOUBLE received -> %d -> INVALID \n ", vec->type);
        return 0;
    }
    if (vec->size >= vec->capacity)
    {
        size_t __new__capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if (!resize_vector(vec, __new__capacity))
        {
            return 0;
        }
    }
    vec->data[vec->size] = malloc(sizeof(double));
    if (vec->data[vec->size] == NULL)
        return 0;

    *(double *)(vec->data[vec->size]) = value;
    ++vec->size;
    return 1;
}

void *at(Vector *vec, size_t index)
{
    if (index >= vec->size)
    {
        fprintf(stderr, "Error: Index out of bounds\n");
        return NULL;
    }
    return vec->data[index];
}

int empty_vector(Vector *vec)
{
    return vec->size == 0;
}
size_t vector_size(Vector *vec)
{
    return vec->size;
}
size_t vector_capacity(Vector *vec)
{
    return vec->capacity;
}
