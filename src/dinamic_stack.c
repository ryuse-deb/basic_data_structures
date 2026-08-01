#include <stdio.h>
#include <stdlib.h>
#include "dinamic_stack.h"
#include "doubly_linked_list.h"

// DATA AND STRUCT DEFINITION===========================================
typedef struct _dinamic_stack {
	List* data;
} DinamicStack;


// FUNCTIONS============================================================

//CONSTRUCTORS AND DESTRUCTORS------------------------------------------
DinamicStack* DinamicStack_create(void) {
	DinamicStack* S = calloc(1, sizeof(DinamicStack));
	S->data = List_create();
	
	return S;
	}
	
void DinamicStack_destroy(DinamicStack** S_ref) {
	DinamicStack* S = *S_ref;
	
	List_destroy(&S->data);
	free(S);
	*S_ref = NULL;
	}

// MANIPULATORS---------------------------------------------------------
ds_status DinamicStack_push(DinamicStack* S, int value) {
	if(S == NULL) {
		return DS_NULL;
		}
	else{
		List_add_last(S->data, value);
		return DS_OK;
		}
	}

ds_status DinamicStack_pop(DinamicStack* S) {
	if(S == NULL) {
		return DS_NULL;
		}
	else{
		if(List_IsEmpty(S->data)) {
			return DS_EMPTY;
			}
		else{
			List_remove_tail(S->data);
			return DS_OK;
			}
		}
	}
	
// INFO-----------------------------------------------------------------
ds_status DinamicStack_print(const DinamicStack* S) {
	if(S == NULL) {
		return DS_NULL;;
		}
	else {
		List_print(S->data);
		return DS_OK;
		}
	}
	
int DinamicStack_peek(const DinamicStack* S) {
	if(List_IsEmpty(S->data)){
		return -1;
		}
	else{
		int val = List_return_head(S->data);
		return val;
		}
	}
