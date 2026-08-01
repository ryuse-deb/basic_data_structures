#ifndef DINAMIC_STACK_H
#define DINAMIC_STACK_H

#include "ds_status.h"
#include "doubly_linked_list.h"

//STRUCTS AND DATATYPES
typedef struct _dinamic_stack DinamicStack;

//FUNCTIONS SIGNATURES
DinamicStack* DinamicStack_create(void);
void DinamicStack_destroy(DinamicStack** S_ref);
	 
ds_status DinamicStack_push(DinamicStack* S, int value);
ds_status DinamicStack_pop(DinamicStack* S);

ds_status DinamicStack_print(const DinamicStack* S);
int DinamicStack_peek(const DinamicStack* S);

#endif
