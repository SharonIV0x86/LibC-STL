#ifndef ITERATOR_H
#define ITERATOR_H
#include "./Vector.h"
// #include "./Types.h"

Iterator *create_iterator(VectorContainerType type, void* container);
void Advance(Iterator *itr);
void Advance_by(Iterator *itr, size_t step);
Iterator *Begin(void *container);

#endif /*ITERATOR_H*/