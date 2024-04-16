 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntArray.h"
/*test the IntArray functions*/


//todo: add time check for different sizes of array

int main(int nWords, char *words[]) {
    // if the input received is -s 29 then we will create a random list of array
    //else code works as normal
    if(!strcpy(words[1],"-s"))
    {
        int size=atoi(words[2]);
        IntArray array = createRandomArray(size);
        if(!array) {
            return 1;
        }
        displayArray(array, size);
        sortArray(array, size);
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
    else
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
        sortArray(array, size);
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

    return 0;
}