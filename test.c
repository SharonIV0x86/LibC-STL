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
    for (int i = 90; i < 100; i++)
    {
        printf("Pushing value: %d ", i);
        push_Back(int_vector, i);
    }
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
    push_Back(char_vector, (char)'\n');
    push_Back(char_vector, (char)'L');
    push_Back(char_vector, (char)'i');
    push_Back(char_vector, (char)'b');
    push_Back(char_vector, (char)'C');
    push_Back(char_vector, (char)'S');
    push_Back(char_vector, (char)'T');
    push_Back(char_vector, (char)'L');
    push_Back(float_vector, 1.2f);
    push_Back(float_vector, 2.4f);
    push_Back(double_vector, 3.43234);
    push_Back(double_vector, 3.43234);
    push_Back(double_vector, 3.43234);
    push_Back(double_vector, 3.43234);
    push_Back(double_vector, 3.43234);

    printf("Int vector:\n");
    for (int i = 0; i < vector_size(int_vector); ++i)
    {
        printf("%d ", AtInt(int_vector, i));
    }
    printf("\n");

    printf("Float vector:\n");
    for (size_t i = 0; i < vector_size(float_vector); ++i)
    {
        printf("%f", AtFloat(float_vector, i));
    }
    printf("\n");

    printf("Char vector:\n");
    for (size_t i = 0; i < vector_size(char_vector); ++i)
    {
        printf("%c", AtChar(char_vector, i));
    }
    printf("\n");

    printf("Double vector:\n");
    for (size_t i = 0; i < vector_size(double_vector); ++i)
    {
        printf("%f ", AtDouble(double_vector, i));
    }
    printf("\n");

    if (empty_vector(int_vector))
        printf("Vector is empty! \n");
    else
        printf("Vector is not empty! \n");

    printf("Size of int_vector %zu \n", vector_size(int_vector));
    printf("Size of float_vector %zu \n", vector_size(float_vector));
    printf("Size of char_vector %zu \n", vector_size(char_vector));
    printf("Size of double_vector %zu \n", vector_size(double_vector));

    //access vector data
    VectorDataInt data = get_vector_int(int_vector);
    if (data)
    {
        for (size_t i = 0; i < vector_size(int_vector); ++i)
        {
            printf("Value at index %zu: %d\n", i,  *data[i]);
        }
    }
    printf("\nModifying the vector by random access! \n");
    if(data){
        for(int i = 0; i < vector_size(int_vector); ++i){
            *data[i] += 12;
        }
    }
    printf("\nFINAL!\n");
    for (size_t i = 0; i < vector_size(int_vector); i++)
    {
        printf("%d ", AtInt(int_vector, i));
    }
    delete_vector(int_vector);
    delete_vector(float_vector);
    delete_vector(char_vector);
    delete_vector(double_vector);

    return 0;
}
