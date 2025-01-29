#include "../include/Vector.h"

MemoryPool *create_pool(size_t block_size) {
    MemoryPool *pool = (MemoryPool *)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;
    
    pool->blocks = malloc(block_size);
    if (!pool->blocks) {
        free(pool);
        return NULL;
    }
    
    pool->block_size = block_size;
    pool->used = 0;
    return pool;
}

void *pool_alloc(MemoryPool *pool, size_t size) {
    if (pool->used + size > pool->block_size) {
        return NULL; 
    }
    
    void *ptr = (char *)pool->blocks + pool->used;
    pool->used += size;
    return ptr;
}

void destroy_pool(MemoryPool *pool) {
    if (pool) {
        free(pool->blocks);
        free(pool);
    }
}

// Vector Functions
Vector *vector_create(size_t element_size) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (!vec) return NULL;

    vec->element_size = element_size;
    vec->capacity = 4;
    vec->size = 0;
    vec->data = malloc(vec->capacity * element_size);
    
    if (!vec->data) {
        free(vec);
        return NULL;
    }
    
    return vec;
}

void vector_destroy(Vector *vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}
VectorStatus vector_push_back(Vector *vec, void *element) {
    if (!vec || !element) return VECTOR_FAILURE;

    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        void *new_data = realloc(vec->data, new_capacity * vec->element_size);
        
        if (!new_data) return VECTOR_OUT_OF_MEMORY;

        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    memcpy((char *)vec->data + vec->size * vec->element_size, element, vec->element_size);
    vec->size++;
    return VECTOR_SUCCESS;
}


void *vector_at(Vector *vec, size_t index) {
    if (!vec || index >= vec->size) return NULL;
    return (char *)vec->data + index * vec->element_size;
}

bool vector_empty(Vector *vec) {
    return vec->size == 0;
}

size_t vector_size(Vector *vec) {
    return vec->size;
}
