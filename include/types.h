#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#ifndef TYPES_H
#define TYPES_H
#pragma once
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
    void *(*at)(void *, size_t);
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
    // size_t container_size;
    conProp pointing_container_properties;

} Iterator;


#endif /* TYPES_H */