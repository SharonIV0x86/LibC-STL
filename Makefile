CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = src/Vector.c test.c
OBJ = obj/Vector.o obj/test.o
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

obj/Vector.o: src/Vector.c
	$(CC) $(CFLAGS) -c src/Vector.c -o obj/Vector.o

obj/test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o obj/test.o

clean:
	rm -f obj/*.o $(TARGET)
