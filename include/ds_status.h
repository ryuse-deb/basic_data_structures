#ifndef DS_STATUS_H
#define DS_STATUS_H

typedef enum {
    DS_OK = 0,
    DS_NULL = 1,
    DS_EMPTY = 2,
    DS_NOT_FOUND = 3,
    DS_OUT_OF_MEMORY = 4,
    DS_INVALID_ARGUMENT = 5,
    DS_ALLOC_ERROR = 6,
    DS_FULL = 7
} ds_status;

#endif
