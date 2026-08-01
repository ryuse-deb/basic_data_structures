#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include "ds_status.h"

//STRUCTS AND DATATYPES
typedef struct _static_queue StaticQueue;

//FUNCTIONS SIGNATURES
StaticQueue* StaticQueue_create(long capacity);
void StaticQueue_destroy(StaticQueue** SQ_ref);

ds_status StaticQueue_enqueue(StaticQueue* SQ, int value);
ds_status StaticQueue_dequeue(StaticQueue* SQ);

ds_status StaticQueue_print(const StaticQueue* SQ);
ds_status StaticQueue_peek(const StaticQueue* SQ);
int StaticQueue_IsEmpty(const StaticQueue* SQ);
int StaticQueue_IsFull(const StaticQueue* SQ);

#endif
