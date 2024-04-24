#include <stdio.h>
#include <stdlib.h>
// This program takes in command line arguments and adds them together
// Example: ./lect1 1 2 3 4 5
// Output: 'Sum: 15
int main(int argc, char *argv[]) {
    int sum = 0;
    //check if there are any arguments
    if (argc == 1) {
        printf("No arguments provided\n");
        return 1;
    }
    // check if the arguments are numbers
    for (int i = 1; i < argc; i++) { // Loop through all the arguments
        for (int j = 0; argv[i][j] != '\0'; j++) {// Loop through each character in the argument
            if (argv[i][j] < '0' || argv[i][j] > '9') {
                printf("Invalid argument: %s\n", argv[i]);
                return 1;
            }
        }
    }
    // Loop through all the arguments and add them together
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        sum += num;
    }
    printf("Sum: %d\n", sum);
    return 0;
}