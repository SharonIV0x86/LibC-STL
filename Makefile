CC=gcc
CFLAGS=-Iinclude
SRC_DIR=src
OBJ_DIR=obj

# List all source files
SRCS=$(wildcard $(SRC_DIR)/*.c)

# Generate corresponding object file names
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(OBJS) test.c
	$(CC) $(CFLAGS) $(OBJS) test.c -o LibC_STLtest

# Rule to compile each source file into object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) LibC_STLtest
