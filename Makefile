CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = src/Vector.c src/Vector_iterator.c test.c
OBJ = obj/Vector.o obj/Vector_iterator.o obj/test.o
TARGET = test

all: obj $(TARGET)
	rm -rf obj  # Remove the obj directory after building the executable

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

obj/Vector.o: src/Vector.c | obj
	$(CC) $(CFLAGS) -c src/Vector.c -o obj/Vector.o 

obj/Vector_iterator.o: src/Vector_iterator.c | obj
	$(CC) $(CFLAGS) -c src/Vector_iterator.c -o obj/Vector_iterator.o 

obj/test.o: test.c | obj
	$(CC) $(CFLAGS) -c test.c -o obj/test.o

obj:
	mkdir -p obj

clean:
	rm -rf obj $(TARGET)
