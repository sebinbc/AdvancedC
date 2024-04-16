# Makefile for C project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# Targets
all: myprogram

myprogram: main.c
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f myprogram
