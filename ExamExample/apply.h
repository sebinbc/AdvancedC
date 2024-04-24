#ifndef APPLY_H
#define APPLY_H
#include <stddef.h> // for size_t

void apply(void *array, int num_elements, size_t element_size, void (*func)(void *), void *result_array);

#endif /* APPLY_H */
