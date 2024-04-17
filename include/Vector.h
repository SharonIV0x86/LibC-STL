#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "./types.h"

void *at(Vector *vec, size_t index);
Iterator *create_iterator(DataType type, void *container)
{
    Iterator *iterator = (Iterator *)malloc(sizeof(Iterator));
    iterator->type = type;
    iterator->index = 0;
    iterator->container = container;
    
    if(setContainerIteratorPropertiesAsPerType(type, iterator, container));
    // if(type == VECTOR_INT){
    // printf("\nIterator pointing to vector_int \n");
    // iterator->pointing_container_properties.size = ((Vector *)container)->size;
    // iterator->pointing_container_properties.capacity = ((Vector *)container)->capacity;
    // }
    if (container != NULL)
    {
        if (iterator != NULL)
        {
            iterator->data = at(container, 0);
        }
        return iterator;
    }
    return iterator;
}
void advance(Iterator *itr)
{
    if (itr != NULL && itr->data != NULL)
    {
        itr->data = at(itr->container, itr->index + 1);
        itr->index++;
    }
}
void advance_by(Iterator *itr, size_t step)
{
    if (itr != NULL && itr->data != NULL && step >= 0)
    {
        itr->data = at(itr->container, itr->index + step);
        itr->index += step;
    }
}
void itr_reset(Iterator *itr)
{
    if (itr != NULL && itr->data != NULL)
    {
        itr->data = at(itr->container, 0);
    }
}

Vector *create_vector(size_t capacity, DataType type)
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
    int *val = (int *)malloc(sizeof(int));
    *val = value;
    vec->data[vec->size++] = val;
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
    float *val = (float *)malloc(sizeof(float));
    *val = value;
    vec->data[vec->size++] = val;
    return 1;
}
int pb_char(Vector *vec, char ch)
{
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
    char *character = (char *)malloc(sizeof(char));
    *character = ch;
    vec->data[vec->size++] = character;
    return 1;
}
int pb_string(Vector *vec, char string[])
{
    if (vec->type != STR)
    {
        printf("\n Expected type to be STR received -> %d -> INVALID \n ", vec->type);
    }
    if (vec->size >= vec->capacity)
    {
        size_t __new__capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if (!resize_vector(vec, __new__capacity))
        {
            return 0;
        }
    }
    char *new_str = (char *)malloc((strlen(string) + 1) * sizeof(char));
    if (new_str == NULL)
    {
        return 0;
    }
    strcpy(new_str, string);
    vec->data[vec->size++] = new_str;
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
    double *doub = (double *)malloc(sizeof(float));
    *doub = value;
    vec->data[vec->size++] = doub;
    return 1;
}

void *at(Vector *vec, size_t index)
{
    if (vec->type == STR)
    {
        char *str = (char *)vec->data[index];
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        { // for removing leading new line character from the strings using fgets()
            str[len - 1] = '\0';
        }
    }

    return (index < vec->size) ? vec->data[index] : NULL;
}

int empty_vector(Vector *vec)
{
    return vec->size == 0;
}
