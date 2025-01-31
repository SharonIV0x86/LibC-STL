#include "Vector.h"

vector_iterator* create_iterator(Vector *vector){
    if(!vector) return NULL;

    vector_iterator* itr = (vector_iterator*)malloc(sizeof(vector_iterator));

    if(!itr) return NULL;

    itr->vector = vector;
    itr->item = (vector->size > 0) ? vector_at(vector, 0) : NULL;

    return itr;
}

bool iterator_has_next(vector_iterator *itr){
    return itr && itr->pos < itr->vector->size;
}
void *iterator_next(vector_iterator* itr){
    if(!iterator_has_next(itr))
        return NULL;

    itr->item = vector_at(itr->vector, itr->pos);
    itr->pos++;

    return itr->item;
}
void destroy_iterator(vector_iterator *itr){
    free(itr);
}
vector_iterator *iterator_front(Vector *vector){
    if(!vector) return NULL;
    vector_iterator *vitr = (vector_iterator*)malloc(sizeof(vector_iterator));

    if(!vitr) return NULL;
    // if(vector->size)
    
    
    vitr->item = vector->data;
    vitr->pos = 0;

    return vitr;

}
