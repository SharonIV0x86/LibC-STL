#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#define VECTOR_POOL_BLOCK_SIZE 1024

typedef enum {
    VECTOR_SUCCESS,
    VECTOR_FAILURE,
    VECTOR_OUT_OF_MEMORY,
} VectorStatus;

typedef struct {
    void *data;
    size_t element_size;
    size_t capacity;
    size_t size;
} Vector;

typedef struct MemoryPool {
    void *blocks;
    size_t block_size;
    size_t used;
} MemoryPool;

MemoryPool *create_pool(size_t block_size);
void *pool_alloc(MemoryPool *pool, size_t size);
void destroy_pool(MemoryPool *pool);

Vector *vector_create(size_t element_size);
void vector_destroy(Vector *vec);
VectorStatus vector_push_back(Vector *vec, void *element);
void *vector_at(Vector *vec, size_t index);
bool vector_empty(Vector *vec);
size_t vector_size(Vector *vec);

#endif 
