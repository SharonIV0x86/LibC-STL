#include <stdio.h>
#include "./include/Vector.h"

typedef struct mystruct
{
    int data;
    char *name;
} MyStruct;

int main()
{
    Vector *int_vec = vector_create(sizeof(int));

    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {
        vector_push_back(int_vec, &values[i]);
    }

    printf("Integer Vector:\n");
    for (size_t i = 0; i < vector_size(int_vec); i++)
    {
        printf("%d ", *(int *)vector_at(int_vec, i));
    }
    printf("\n");

    vector_destroy(int_vec);

    Vector *double_vec = vector_create(sizeof(double));

    double dvalues[] = {1.1, 2.2, 3.3, 4.4};
    for (int i = 0; i < 4; i++)
    {
        vector_push_back(double_vec, &dvalues[i]);
    }

    printf("Double Vector:\n");
    for (size_t i = 0; i < vector_size(double_vec); i++)
    {
        printf("%.1f ", *(double *)vector_at(double_vec, i));
    }
    printf("\n");

    vector_destroy(double_vec);
    MyStruct v1 = {10, "Jasper"};
    MyStruct v2 = {20, "Kasper"};
    MyStruct v3 = {30, "Hasper"};
    MyStruct v4 = {40, "Gasper"};

    Vector *custom_vec = vector_create(sizeof(MyStruct));
    vector_push_back(custom_vec, &v1);
    vector_push_back(custom_vec, &v2);
    vector_push_back(custom_vec, &v3);
    vector_push_back(custom_vec, &v4);
     
    for(size_t i = 0; i < vector_size(custom_vec); i++){
        MyStruct *item = (MyStruct*)vector_at(custom_vec, i);
        printf("%d %s\n", item->data, item->name);
    }
    vector_iterator *itr = create_iterator(custom_vec);
    while(iterator_has_next(itr)){
        MyStruct *item = (MyStruct *)iterator_next(itr);
        printf("%s ", item->name);
    }
    return 0;
}
