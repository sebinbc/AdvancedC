#ifndef __INTARRAY_H__
#define __INTARRAY_H__

// Define a type IntArray as a pointer to an integer
typedef int * IntArray;

// Function prototypes
// Create an array of integers of the given size
IntArray createArray(int size);
// display the elements of the array
void displayArray(IntArray arr, int size);
// sort the elements of the array
void sortArray(IntArray arr, int size);
// destroy the array
void destroyArray(IntArray *arr);


#endif // __INTARRAY_H__