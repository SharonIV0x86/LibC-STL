#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    STR,
    INT,
    FLOAT,
    CHAR,
    DOUBLE
} DataType;

typedef struct vector
{
    void **data;
    size_t capacity;
    size_t size;
    DataType type;
} Vector;

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
    if(vec->size >= vec->capacity){
        size_t __new__capacity = (vec->capacity == 0) ? 1 : vec->capacity * 1.5;
        if(!resize_vector(vec, __new__capacity)){
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
