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
Vector *create_Vector(size_t, DataType);
void delete_vector(Vector*);
int resize_vector(Vector*, size_t);
int pb_int(Vector*, int);
int pb_float(Vector*, float);
int pb_char(Vector*, char);
// int pb_string(Vector*, char[]); [NOT SUPPORTED FOR NOW]
int pb_double(Vector*, double);
int empty_vector(Vector* vec);
void *at(Vector *, size_t);
