# LibC-STL: A C Implementation of Standard Template Library (STL)

## Overview

C-STL is a project aimed at implementing a subset of the functionality provided by the C++ Standard Template Library (STL) in pure C. The motivation behind this project stems from the efficiency and versatility of the C++ STL, which has been widely acclaimed as one of the most efficient code libraries in C++. This projects aims at implementing C++ STL in C as efficient and as easy to use as possible.

## Motivation
The C++ STL is renowned for its rich collection of data structures, algorithms, and utilities, which simplify and streamline the process of software development in C++. Recognizing the value and efficiency of the STL, this project seeks to bridge this gap by bringing some of the essential features of the STL to the C programming language.

## Project Goals
- Implement core data structures such as vectors, linked lists, stacks, queues, maps, and sets in C.
- Develop efficient algorithms for common operations like sorting, searching, and manipulation of data structures.
- Provide a user-friendly interface and intuitive API for easy integration into C projects.
- Ensure compatibility and portability across different platforms and compilers.
- Foster a community of contributors and users to collaborate on further enhancements and improvements.

## Key Features
- **Vector**: Resizable arrays similar to vectors in C++. [Example](#example)
- **Iterators**: C++ style iterators to iterate containers efficiently.
- **Linked List**: Singly linked lists, doubly linked lists, and circular linked lists. [to be implemened]
- **Stacks and Queues**: Implementations using arrays or linked lists. [to be implemened]
- **Maps and Sets**: Hash maps or binary search trees for key-value pairs and unique elements. [to be implemened]
- **String Manipulation**: Functions for manipulating strings, including concatenation, substring extraction, and searching. [to be implemened]
- **Algorithms**: Common algorithms for sorting, searching, and manipulation of sequences. [to be implemened]
- **Error Handling**: Mechanisms for error handling and exception management. [to be implemened]

# Contributing
Contributors are welcomed add more functionalities or fixes..
- Raise an issue about the about feature you want to add and wait for it to assigned to you.
- Or check any existing issue if you want to work on them [Issues](https://github.com/SharonIV0x86/LibC-STL/issues)
- Edit your code and open the PR, documentation will be taken care of. Feel free to share if you have anything extra to add in docs.
- Make sure to add block comments above your added feature.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code according to the terms of the license.

### Note from maintainer
This project serves as a learning endeavor for me to explore dynamic memory management in C, gaining insights into the STL in C++, and honing skills in library design and DSA. I'm eager to see this project flourish and evolve further.

## Example
```c
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
    push_Back(float_vector, 1.2f);
    push_Back(double_vector, 3.43234);
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

```

## Feedback and Support
If you have any feedback, suggestions, or questions regarding the project, please feel free to open an issue.

## Acknowledgements
We would like to express our gratitude to the creators and maintainers of the C++ STL, whose work has inspired this project. Additionally, we thank all contributors and users for their valuable feedback and contributions.
