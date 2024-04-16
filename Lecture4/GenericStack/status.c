//if a program successfully executes, it returns 0
//it is the responsibility of the author to ensure that the program returns 0
//else he should document the return value

#include <stdio.h>
#include "status.h"
// detailed message from the enum of status_t

// it is important to make this static because it is not used outside this file
// if it is not static, it will be visible to other files
// and this will be an issue if there is another variable with the same name
// in another  file
static char * message[]={ "SUCCESS",
    "FAILURE",
    "memory allocation failed",
    "ERR_DATA_NOT_FOUND",
    "ERR_EMPTY",
    "ERR_OPEN_FAIL",
    "ERR_CLOSE_FAIL",
    "unknown error"
};

char *errorMessages(status_t status){
    return status<ERR_UNKOWN?message[status]:message[ERR_UNKOWN];
}
//we will implement these error messages along with stack.

