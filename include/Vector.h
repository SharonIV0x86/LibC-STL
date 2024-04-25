#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "./Types.h"
#include "./Utils.h"
void *vector_at(Vector *vec, size_t index);
void itr_reset(Iterator *itr);
Vector *create_vector(size_t capacity, DataType type);
void delete_vector(Vector *vec);
int resize_vector(Vector *vec, size_t size);
int pb_int(Vector *vec, int value);
int pb_float(Vector *vec, float value);
int pb_char(Vector *vec, char ch);
int pb_string(Vector *vec, char string[]);
int pb_double(Vector *vec, double value);
int vector_push_back(Vector* vec, void* element);
int empty_vector(Vector *vec);

#endif