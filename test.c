#include <stdio.h>
#include "./include/Vector.h"

int main()
{
    // Creating vectors of different data types
    Vector *int_vector = create_Vector(5, INT);
    Vector *float_vector = create_Vector(5, FLOAT);
    Vector *char_vector = create_Vector(5, CHAR);
    // Vector *str_vector = create_Vector(5, STR);
    Vector *double_vector = create_Vector(5, DOUBLE);

    // Populating vectors
    pb_int(int_vector, 10);
    pb_int(int_vector, 20);
    pb_int(int_vector, 30);

    pb_float(float_vector, 3.14f);
    pb_float(float_vector, 2.71f);

    pb_char(char_vector, 'a');
    pb_char(char_vector, 'b');
    pb_char(char_vector, 'c');

    // pb_string(str_vector, "Hello");
    // pb_string(str_vector, "World");
    // pb_string(str_vector, "Jasper");

    pb_double(double_vector, 1.234);
    pb_double(double_vector, 5.678);

    printf("Int vector:\n");
    for (size_t i = 0; i < int_vector->size; ++i)
    {
        printf("%d ", *(int *)at(int_vector, i));
    }
    printf("\n");

    printf("Float vector:\n");
    for (size_t i = 0; i < float_vector->size; ++i)
    {
        printf("%f ", *(float *)at(float_vector, i));
    }
    printf("\n");

    printf("Char vector:\n");
    for (size_t i = 0; i < char_vector->size; ++i)
    {
        printf("%c ", *(char *)at(char_vector, i));
    }
    printf("\n");

    // printf("String vector:\n");
    // for (size_t i = 0; i < str_vector->size; ++i) {
    //     printf("%s ", (char*)at(str_vector, i));
    // }
    // printf("\n");

    printf("Double vector:\n");
    for (size_t i = 0; i < double_vector->size; ++i)
    {
        printf("%f ", *(double *)at(double_vector, i));
    }
    printf("\n");
    
    if (empty_vector(int_vector))
        printf("Vector is empty! ");
    else
        printf("Vector is not empty! ");

    // Freeing memory
    delete_vector(int_vector);
    delete_vector(float_vector);
    delete_vector(char_vector);
    // delete_vector(str_vector);
    delete_vector(double_vector);

    return 0;
}
