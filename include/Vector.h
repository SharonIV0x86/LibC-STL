#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
typedef struct vector Vector;
typedef enum
{
    STR,
    INT,
    FLOAT,
    CHAR,
    DOUBLE
} DataType;
Vector *create_Vector(size_t, DataType);
void delete_vector(Vector*);
int resize_vector(Vector*, size_t);
int pb_int(Vector*, int);
int pb_float(Vector*, float);
int pb_char(Vector*, char);
int pb_double(Vector*, double);
int empty_vector(Vector* );
void *at(Vector *, size_t);
size_t vector_size(Vector* );

#define push_Back(Container, T) _Generic((T), \
    int: pb_int, \
    float: pb_float, \
    char: pb_char, \
    double: pb_double \
)(Container, T)
