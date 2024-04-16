#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//create an array of the given size
IntArray createArray(int size) {
    IntArray array= (IntArray)malloc(size * sizeof(int));
    if(!array) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for(int i=0; i<size; i++) {
        array[i] = 0;
    }
    return array;
}


void displayArray(IntArray array, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void displayArrayGen(void* array, int size, int elemSize) {
    for(int i=0; i<size; i++) {
        printf("%d ", *((int*)((char*)array+i*elemSize)));
    }
    printf("\n");
}

void destroyArray(IntArray * arr)
{
    free(*arr);
    *arr=NULL;
}
/*bubble sort*/
void sortArray(IntArray array, int size) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/*IntArray createRandomArray(int size) create an array of the given size filled with random values in 0--2size-1
use srand(time(NULL)) to initialize the random number generator
srand(getpid()) can be used to initialize the random number generator with the process id if in unix
*/
#include <stdlib.h> // Include the missing header file

IntArray createRandomArray(int size) {
    IntArray array= (IntArray)malloc(size * sizeof(int));
    if(!array) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for(int i=0; i<size; i++) {
        //random number between 0 and 2*size-1
        array[i] = rand() % (2*size);
    }
    return array;
}


//using function pointer
void sortArrayUsingFunctionPointer(IntArray array, int size, int (*compare)(int, int)) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(compare(array[i], array[j]) > 0) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int compareAscending(int a, int b) {
    return a-b;
}



int compareDescending(int a, int b) {
    return b-a;
}

// more generalized version of sortArrayUsingFunctionPointer
void sortArrayUsingFunctionPointerGen(void* array, int size, int elemSize, int (*compare)(void*, void*)) {
    int l,r;
    int end= size*elemSize;
    void *temp = malloc(elemSize);

    for(l=0; l<end-elemSize; l+=elemSize) {
        for(r=l+elemSize; r<end; r+=elemSize) {
            if(compare((char*)array+l,(char*)array+r) > 0) {
                memcpy(temp, (char*)array+l, elemSize);
                memcpy((char*)array+l, (char*)array+r, elemSize);
                memcpy((char*)array+r, temp, elemSize);
            }
        }
    }
    free(temp);
}

int compInt(void* p1, void* p2) {
    int *a = (int*)p1;
    int *b = (int*)p2;
    return *a - *b;
}
//comp string
int compStr(void* p1, void* p2) {
    char *a = (char*)p1;
    char *b = (char*)p2;
    return strcmp(a, b);
    //return strcmp(*(char**)p1, *(char**)p2);
}




