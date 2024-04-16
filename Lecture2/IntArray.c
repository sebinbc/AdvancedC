#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**/
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
IntArray createRandomArray(int size) {
    IntArray array= (IntArray)malloc(size * sizeof(int));
    srand(time(NULL));
    if(!array) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for(int i=0; i<size; i++) {
        array[i] = rand() % 2*size;
    }
    return array;
}

