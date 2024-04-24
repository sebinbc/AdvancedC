#include <stdio.h>
#include "apply.h"

// Example function to triple the value of an integer
void triple(void *ptr) {
    int *val = (int *)ptr;
    *val = (*val) * 3;
}

int main() {
    int a[] = {1, 4, 2, 8, 5, 7};
    int b[6]; // Result array
    apply(a, 6, sizeof(int), triple, b);
    // Print the values in array b to verify
    printf("Result array b: {");
    for (int i = 0; i < 6; ++i) {
        printf("%d", b[i]);
        if (i != 5)
            printf(", ");
    }
    printf("}\n");

    return 0;
}
