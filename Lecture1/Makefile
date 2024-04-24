# Makefile
# Reference: https://makefiletutorial.com/#getting-started
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g
# -Wall: Enable all warnings
# -Wextra: Enable some extra warnings
# -g: Generate debug information

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = myprogram

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
# Usage: make clean
clean:
# check the kind of system calling it windows or linux
ifeq ($(OS),Windows_NT)
	del .\$(OBJS) .\$(TARGET).exe
else
	rm -f $(OBJS) $(TARGET)
endif