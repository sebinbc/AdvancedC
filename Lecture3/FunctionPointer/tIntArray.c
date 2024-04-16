 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntArray.h"
#include <time.h>
/*test the IntArray functions*/

#define NDEBUG 

//todo: add time check for different sizes of array
#ifdef NDEBUG
int main(int nWords, char *words[]) {
#else
int main() {
#endif
    // if the input received is -s 29 then we will create a random list of array
    //else code works as normal
    //fill a string array with random values
    char * strings[] = {"apple", "send", "this", "is", "a", "test"};
    sortArrayUsingFunctionPointerGen(strings, sizeof(strings)/sizeof(char*), sizeof(char*), compStr);
    for(size_t i=0; i<sizeof(strings)/sizeof(char*); i++) {
        printf("%s ", strings[i]);
    }
    //displayArrayGen(strings, sizeof(strings)/sizeof(char*), sizeof(char*));

    #ifdef NDEBUG 
    if(!strcmp(words[1],"-s"))
    {
        printf("Random Array\n");
        int size=atoi(words[2]);
        IntArray array = createRandomArray(size);
        if(!array) {
            return 1;
        }
        displayArray(array, size);
        //sortArray(array, size);
        //sortArrayUsingFunctionPointer(array, size,compareAscending);
        //sortArrayUsingFunctionPointerGen(array,size,sizeof(int),compInt);
        //test time taken for sorting
        time_t start, end;
        start = time(NULL); // get the current time
        qsort(array, size, sizeof(int), compInt);
        end = time(NULL); // get the current time
        printf("Time taken for sorting: %ld\n", end-start);
        displayArray(array, size);
        destroyArray(&array);
        if(array==0){
            printf("Array is destroyed\n");
            return 0;
        }
        else{
            return 2;
        }
    }
    else if(0)//for testing string
    {
        //size of the input argument and create array of
        //size of the input argument
        int size=nWords-1;
        IntArray array = createArray(size);
        if(!array) {
            return 1;
        }
        for(int i=1;i<size;i++)
        {
            array[i-1]=atoi(words[i]);
        }

        displayArray(array, size);
        //sortArrayUsingFunctionPointer(array, size,compareAscending);
        displayArray(array, size);
        destroyArray(&array);
        if(array==0){
            printf("Array is destroyedAS\n");
            return 0;
        }
        else{
            return 2;
        }
    }
    #endif

    return 0;
}