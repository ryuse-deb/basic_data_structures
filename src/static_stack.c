#include <stdio.h>
#include <stdlib.h>

#include "static_stack.h"
//#include "ds_status.h"

// DATA AND STRUCT DEFINITION===========================================
typedef struct _static_stack {
	int* data;
	int capacity;
	int top;	
} StaticStack;

// FUNCTIONS============================================================

// CONSTRUCTORS AND DESTRUCTORS-----------------------------------------
StaticStack* StaticStack_create(int capacity) {
	StaticStack* stack = calloc(1, sizeof(StaticStack));
	
	stack->capacity = capacity;
	stack->top = -1;
	stack->data = calloc(capacity, sizeof(int));
	
	return stack;
	}
	
void StaticStack_destroy(StaticStack** S_ref) {
	StaticStack* stack = *S_ref;
	
	free(stack->data);
	free(stack);
	*S_ref = NULL;
	}
	
// MANIPULATORS---------------------------------------------------------

ds_status StaticStack_push(StaticStack* S, int value) {
	if(S == NULL) {
		return DS_NULL;
		}
	else {
		if(StaticStack_IsFull(S)) {
			return DS_FULL;
			}
		else {
			S->top++;
			S->data[S->top] = value;
			return DS_OK;
			}
		}
	}
	
	
ds_status StaticStack_pop(StaticStack* S) {
	if(S == NULL) {
		return DS_NULL;;
		}
	else{
		if (StaticStack_IsEmpty(S)) {
			return DS_EMPTY;
			}
		else {
			S->top--;
			return DS_OK;
			}
		}
	
	}
	
// INFO-----------------------------------------------------------------
ds_status StaticStack_print(const StaticStack* S) {
	if(S == NULL) {
		return DS_NULL;
		}
	else{
		if (StaticStack_IsEmpty(S)) {
			return DS_EMPTY;
			}
		else {
			for(int i = S->top; i >= 0; --i) {
				printf("%d\n", S->data[i]);
				}
			return DS_OK;
			}
		}
	}
	
int StaticStack_peek(const StaticStack* S) {
	return S->data[S->top];
	}
	
int StaticStack_IsEmpty(const StaticStack* S) {
	return (S->top < 0);
	}
	
int StaticStack_IsFull(const StaticStack* S) {
	return(S->top == (S->capacity-1));
	}

