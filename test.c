#include "./include/Vector.h"
#include "./include/Iterator.h"
int main()
{
    // Creating vectors for different data types
    Vector *int_vector = create_vector(5, INT);
    Vector *float_vector = create_vector(5, FLOAT);
    Vector *char_vector = create_vector(5, CHAR);
    Vector *string_vector = create_vector(5, STR);
    Vector *double_vector = create_vector(5, DOUBLE);
    // Pushing data into the vectors
    pb_int(int_vector, 10);
    pb_int(int_vector, 20);
    pb_int(int_vector, 30);
    pb_int(int_vector, 40);
    pb_int(int_vector, 50);
    pb_int(int_vector, 60);
    pb_int(int_vector, 70);
    pb_int(int_vector, 80);
    pb_int(int_vector, 90);
    pb_int(int_vector, 100);
    pb_int(int_vector, 110);

    pb_float(float_vector, 3.14f);
    pb_float(float_vector, 2.718f);
    pb_float(float_vector, 1.618f);

    pb_char(char_vector, 'a');
    pb_char(char_vector, 'b');
    pb_char(char_vector, 'c');

    // pb_string(string_vector, "The cat meows");
    // pb_string(string_vector, "The dog barks");
    // pb_string(string_vector, "The cow moos");

    // Inputting string with fgets
    printf("Enter the string: ");
    char strr[30] = " ";
    pb_string(string_vector, fgets(strr, sizeof(strr), stdin));

    pb_double(double_vector, 3.14159);
    pb_double(double_vector, 2.71828);
    pb_double(double_vector, 1.41421);


    int a = 120;
    int b = 130;
    int c = 140;
    int d = 150;
    int e = 160;
    int f = 170;
    
    vector_push_back(int_vector, &a);
    vector_push_back(int_vector, &b);
    vector_push_back(int_vector, &c);
    vector_push_back(int_vector, &d);
    vector_push_back(int_vector, &e);
    vector_push_back(int_vector, &f);

    // Accessing elements in the vectors
    printf("Int Vector:\n");
    for (size_t i = 0; i < int_vector->size; ++i) {
        // int *value = (int *)at(int_vector, i);
        printf("%d\n", *(int *)vector_at(int_vector, i));
    }

    // printf("Float Vector:\n");
    // for (size_t i = 0; i < float_vector->size; ++i) {
    //     float *value = (float *)at(float_vector, i);
    //     printf("%f\n", *value);
    // }

    // printf("Char Vector:\n");
    // for (size_t i = 0; i < char_vector->size; ++i) {
    //     char *value = (char *)at(char_vector, i);
    //     printf("%c\n", *value);
    // }

    // printf("String Vector: ");
    // for (size_t i = 0; i < string_vector->size; ++i) {
    //     puts((char *)(at(string_vector, i)));
    // }
    Iterator *it = create_iterator(VECTOR_INT, int_vector);
    printf("Value at 1: %d \n", *((int *)it->data));
    Advance(it);
    printf("Value at 2: %d \n", *((int *)it->data));
    Advance_by(it, 4);
    printf("Value at 6: %d \n", *((int *)it->data));

    Iterator *beginItr = create_iterator(VECTOR_INT, int_vector);
    printf("Value at itr begin: %d \n", *(int *)Begin(int_vector)->data);

    int* firstElement = Begin(int_vector)->data;
    printf("First's value: %d", *firstElement);

    // Deleting vectors to free memory
    delete_vector(int_vector);
    delete_vector(float_vector);
    delete_vector(char_vector);
    delete_vector(string_vector);

    return 0;
}