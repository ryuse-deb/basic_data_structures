#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include "ds_status.h"

//STRUCTS AND DATATYPES
typedef struct _static_stack StaticStack;

//FUNCTIONS SIGNATURES
StaticStack* StaticStack_create(int capacity);
void StaticStack_destroy(StaticStack** S_ref);

ds_status StaticStack_push(StaticStack* S, int value);
ds_status StaticStack_pop(StaticStack* S);

ds_status StaticStack_print(const StaticStack* S);
int StaticStack_peek(const StaticStack* S);
int StaticStack_IsEmpty(const StaticStack* S);
int StaticStack_IsFull(const StaticStack* S);

#endif
