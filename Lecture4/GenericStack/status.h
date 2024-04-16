#ifndef __STATUS_H__
#define __STATUS_H__

//define all possible errors in an enum
typedef enum {
    SUCCESS = 0,
    FAILURE = 1,
    ERR_ALLOC_FAIL = 2,
    ERR_DATA_NOT_FOUND = 3,
    ERR_EMPTY = 4,
    ERR_OPEN_FAIL = 5,
    ERR_CLOSE_FAIL = 6,
    ERR_UNKOWN = 7

} status_t;
//define a function to print the error message
char *errorMessages(status_t status);
#endif