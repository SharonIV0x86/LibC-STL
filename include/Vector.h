#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
// typedef struct vector Vector;
typedef int** VectorDataInt ;
typedef float** VectorDataFloat ;
typedef char** VectorDataChar ;
typedef double** VectorDataDouble ;
typedef enum
{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
} DataType;
typedef enum
{
    INT_INSERT_SUCCESS,
    FLOAT_INSERT_SUCCESS,
    CHAR_INSERT_SUCCESS,
    DOUBLE_INSERT_SUCCESS,

    INT_INSERT_FAILED,
    FLOAT_INSERT_FAILED,
    CHAR_INSERT_FAILED,
    DOUBLE_INSERT_FAILED,
} StatusCodes;
typedef struct vector
{
    void **data;
    size_t capacity;
    size_t size;
    DataType type;

    // Function pointers for accessing elements of the vector
    // int (*AtInt)(struct vector *, int);
    // float (*AtFloat)(struct vector *, int);
    // char (*AtChar)(struct vector *, int);
    // double (*AtDouble)(struct vector *, int);
} Vector;

Vector *create_Vector(size_t, DataType);
void delete_vector(Vector *);
int resize_vector(Vector *, size_t);
int LIBC_INTERNAL_pb_int(Vector *, int);
int LIBC_INTERNAL_pb_float(Vector *, float);
int LIBC_INTERNAL_pb_char(Vector *, char);
int LIBC_INTERNAL_pb_double(Vector *, double);

StatusCodes LIBC_INTERNAL_insert_int(Vector *, int, size_t);
StatusCodes LIBC_INTERNAL_insert_float(Vector *, float, size_t);
StatusCodes LIBC_INTERNAL_insert_char(Vector *, char, size_t);
StatusCodes LIBC_INTERNAL_insert_double(Vector *, double, size_t);

// int LIBC_INTERNAL_at_int(Vector *, int);
// float LIBC_INTERNAL_at_float(Vector *, int);
// char LIBC_INTERNAL_at_char(Vector *, int);
// double LIBC_INTERNAL_at_double(Vector *, int);

int AtInt(Vector *, int);
float AtFloat(Vector *, int);
char AtChar(Vector *, int);
double AtDouble(Vector *, int);

int** get_vector_int(Vector *);

int empty_vector(Vector *);
void *at(Vector *, size_t);
size_t vector_size(Vector *);

#define vector_at(Container, T) _Generic(Container->type, \
    INT: _Generic(Container->type, \
            INT: AtInt)(Container, T) \
    FLOAT: _Generic(Container->type, \
            FLOAT: AtFloat)(Container, T)\
)(Container, T)


#define push_Back(Container, T) _Generic((T), \
    int: LIBC_INTERNAL_pb_int,                \
    float: LIBC_INTERNAL_pb_float,            \
    char: LIBC_INTERNAL_pb_char,              \
    double: LIBC_INTERNAL_pb_double)(Container, T)

// #define AtInt(Container, Index) LIBC_INTERNAL_at_int(Container, Index)
// #define AtFloat(Container, Index) LIBC_INTERNAL_at_float(Container, Index)
// #define AtChar(Container, Index) LIBC_INTERNAL_at_char(Container, Index)
// #define AtDouble(Container, Index) LIBC_INTERNAL_at_double(Container, Index)

#endif /* VECTOR_H */
