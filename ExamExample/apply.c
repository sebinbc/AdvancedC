#include "apply.h"
#include <stdlib.h> // for malloc
#include <stddef.h> // for size_t

void apply(void *array, int num_elements, size_t element_size, void (*func)(void *), void *result_array) {
    char *ptr = array;
    char *result_ptr = result_array;
    for (int i = 0; i < num_elements; ++i) {
        func(ptr); // apply the function to the current element
        // Copy the result to the result array
        for (size_t j = 0; j < element_size; ++j) {
            result_ptr[j] = ptr[j];
        }
        ptr += element_size; // Move to the next element
        result_ptr += element_size; // Move to the next position in the result array
    }
}
