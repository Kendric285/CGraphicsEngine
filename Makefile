# Makefile for compiling main.c with SDL2

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I/opt/homebrew/opt/sdl2/include

# Linker flags
LDFLAGS = -L/opt/homebrew/opt/sdl2/lib -lSDL2

# Target executable
TARGET = main

# Source files
SRC = main.c

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

# Clean target
clean:
	rm -f $(TARGET)
