#ifndef DINAMIC_QUEUE_H
#define DINAMIC_QUEUE_H

#include "ds_status.h"
#include "doubly_linked_list.h"

//STRUCTS AND DATATYPES
typedef struct _queue DinamicQueue;

//FUNCTIONS SIGNATURES
DinamicQueue* DinamicQueue_create(void);
void DinamicQueue_destroy(DinamicQueue** DQ_ref);

ds_status DinamicQueue_enqueue(DinamicQueue* DQ, int value);
ds_status DinamicQueue_dequeue(DinamicQueue* DQ);

ds_status DinamicQueue_print(const DinamicQueue* DQ);
int DinamicQueue_peek(const DinamicQueue* DQ);

#endif
