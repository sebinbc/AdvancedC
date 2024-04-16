#ifndef __INTARRAY_H__
#define __INTARRAY_H__


typedef int * IntArray;


IntArray createArray(int size);
void displayArray(IntArray arr, int size);
void sortArray(IntArray arr, int size);
void destroyArray(IntArray *arr);


#endif // __INTARRAY_H__