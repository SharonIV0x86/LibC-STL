#include <stdio.h>
#include "./include/Vector.h"

int main()
{
    // Creating vectors of different data types
    Vector *int_vector = create_Vector(5, INT);
    Vector *float_vector = create_Vector(5, FLOAT);
    Vector *char_vector = create_Vector(5, CHAR);
    Vector *double_vector = create_Vector(5, DOUBLE);
    // Populating vectors
    push_Back(int_vector, 90);
    push_Back(char_vector, (char)'H');
    push_Back(char_vector, (char)'e');
    push_Back(char_vector, (char)'l');
    push_Back(char_vector, (char)'l');
    push_Back(char_vector, (char)'o');
    push_Back(char_vector, (char)'W');
    push_Back(char_vector, (char)'o');
    push_Back(char_vector, (char)'r');
    push_Back(char_vector, (char)'l');
    push_Back(char_vector, (char)'d');
    push_Back(float_vector, 1.2f);
    push_Back(double_vector, 3.43234);

    printf("Int vector:\n");
    for (size_t i = 0; i < vector_size(int_vector); ++i)
    {
        printf("%d ", *(int *)at(int_vector, i));
    }
    printf("\n");

    printf("Float vector:\n");
    for (size_t i = 0; i < vector_size(float_vector); ++i)
    {
        printf("%f ", *(float *)at(float_vector, i));
    }
    printf("\n");

    printf("Char vector:\n");
    for (size_t i = 0; i < vector_size(char_vector); ++i)
    {
        printf("%c", *(char *)at(char_vector, i));
    }
    printf("\n");

    printf("Double vector:\n");
    for (size_t i = 0; i < vector_size(double_vector); ++i)
    {
        printf("%f ", *(double *)at(double_vector, i));
    }
    printf("\n");

    if (empty_vector(int_vector))
        printf("Vector is empty! ");
    else
        printf("Vector is not empty! ");

    printf("Size of int_vector %zu \n", vector_size(int_vector));
    printf("Size of float_vector %zu \n", vector_size(float_vector));
    printf("Size of char_vector %zu \n", vector_size(char_vector));
    printf("Size of double_vector %zu \n", vector_size(double_vector));

    printf("\nTesting generic push back! \n");
    push_Back(int_vector, 90);
    delete_vector(int_vector);
    delete_vector(float_vector);
    delete_vector(char_vector);
    delete_vector(double_vector);

    return 0;
}
