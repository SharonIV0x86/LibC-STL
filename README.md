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
#include "./include/Vector.h"

int main() {
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

    pb_float(float_vector, 3.14f);
    pb_float(float_vector, 2.718f);
    pb_float(float_vector, 1.618f);

    pb_char(char_vector, 'a');
    pb_char(char_vector, 'b');
    pb_char(char_vector, 'c');

    pb_string(string_vector, "The cat meows");
    pb_string(string_vector, "The dog barks");
    pb_string(string_vector, "The cow moos");

    //Inputting string with fgets
    printf("Enter the string: ");
    char strr[30] = " ";
    pb_string(string_vector, fgets(strr, sizeof(strr), stdin));

    pb_double(double_vector, 3.14159);
    pb_double(double_vector, 2.71828);
    pb_double(double_vector, 1.41421);

    // Accessing elements in the vectors
    printf("Int Vector:\n");
    for (size_t i = 0; i < int_vector->size; ++i) {
        int *value = (int *)at(int_vector, i);
        printf("%d\n", *value);
    }

    printf("Float Vector:\n");
    for (size_t i = 0; i < float_vector->size; ++i) {
        float *value = (float *)at(float_vector, i);
        printf("%f\n", *value);
    }

    printf("Char Vector:\n");
    for (size_t i = 0; i < char_vector->size; ++i) {
        char *value = (char *)at(char_vector, i);
        printf("%c\n", *value);
    }

    printf("String Vector: ");
    for (size_t i = 0; i < string_vector->size; ++i) {
        puts((char *)(at(string_vector, i)));
    }

    // Deleting vectors to free memory
    delete_vector(int_vector);
    delete_vector(float_vector);
    delete_vector(char_vector);
    delete_vector(string_vector);

    return 0;
}
```

## Feedback and Support
If you have any feedback, suggestions, or questions regarding the project, please feel free to [open an issue].

## Acknowledgements
We would like to express our gratitude to the creators and maintainers of the C++ STL, whose work has inspired this project. Additionally, we thank all contributors and users for their valuable feedback and contributions.
