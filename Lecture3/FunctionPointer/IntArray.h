#ifndef __INTARRAY_H__
#define __INTARRAY_H__


typedef int * IntArray;


IntArray createArray(int size);

void displayArray(IntArray arr, int size);
void displayArrayGen(void* array, int size, int elemSize);

void sortArray(IntArray arr, int size);
void sortArrayUsingFunctionPointer(IntArray array, int size, int (*compare)(int, int));
IntArray createRandomArray(int size);
void sortArrayUsingFunctionPointerGen(void* array, int size, int elemSize, int (*compare)(void*, void*));
int compareDescending(int a, int b);
int compareAscending(int a, int b);

int compInt(void* p1, void* p2);
int compStr(void* p1, void* p2);
void destroyArray(IntArray *arr);


#endif // __INTARRAY_H__